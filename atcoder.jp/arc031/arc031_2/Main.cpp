# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%1000000007;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
}


int main() {
  vector<string> a(10); for(int i=0;i<10;i++) cin>>a[i];

  /*
  vector< vector<bool> > is_checked(10, vector<bool>(10,false));
  vector< vector< pair<int,int> > > islands;
  for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++) {
      if(is_checked[i][j]) continue;

      if(a[i][j] == 'o') {
        vector< pair<int,int> > island;
        deque< pair<int,int> > dq;
        dq.push_back( pair<int,int>(i,j) );

        while(!dq.empty()) {
          auto cur=dq.front();
          dq.pop_front();
          island.push_back(cur);
          is_checked[cur.first][cur.second] = true;

          if(cur.first+1<10) {
            if(a[cur.first+1][cur.second] == 'o') {
              if(!is_checked[cur.first+1][cur.second]) {
                dq.push_back( pair<int,int>(cur.first+1,cur.second) );
              }
            }
          }

          if(cur.first-1>=0) {
            if(a[cur.first-1][cur.second] == 'o') {
              if(!is_checked[cur.first-1][cur.second]) {
                dq.push_back( pair<int,int>(cur.first-1,cur.second) );
              }
            }
          }

          if(cur.second+1<10) {
            if(a[cur.first][cur.second+1] == 'o') {
              if(!is_checked[cur.first][cur.second+1]) {
                dq.push_back( pair<int,int>(cur.first,cur.second+1) );
              }
            }
          }

          if(cur.second-1>=0) {
            if(a[cur.first][cur.second-1] == 'o') {
              if(!is_checked[cur.first][cur.second-1]) {
                dq.push_back( pair<int,int>(cur.first,cur.second-1) );
              }
            }
          }
        }

        islands.push_back(island);
      }
    }
  }

  int num=islands.size(), max_min_dist=0; // cout<<num<<endl;
  for(int i=0;i<num;i++) {
    for(int j=i+1;j<num;j++) {

      int min_dist=3;
      for(auto xi:islands[i]) {
        for(auto xj:islands[j]) {
          min_dist = min(min_dist, \
           abs(xi.first-xj.first)+abs(xi.second-xj.second));
        }
      }

      max_min_dist = max(max_min_dist, min_dist);
    }
  }

  if(max_min_dist <= 2) cout<<"YES\n";
  else cout<<"NO\n";
  */

  vector< vector<bool> > is_checked(10, vector<bool>(10,false));
  vector< vector< pair<int,int> > > islands;

  for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++) {

      vector< vector<bool> > is_checked(10, vector<bool>(10,false));
      deque< pair<int,int> > dq;
      dq.emplace_back(i,j);
      while(!dq.empty()) {
        auto cur=dq.front();
        dq.pop_front();

        int x=cur.first, y=cur.second;
        is_checked[x][y] = true;

        if(x+1 < 10) {
          if(!is_checked[x+1][y] && a[x+1][y] == 'o') {
            dq.emplace_back(x+1,y);
          }
        }

        if(x-1 >= 0) {
          if(!is_checked[x-1][y] && a[x-1][y] == 'o') {
            dq.emplace_back(x-1,y);
          }
        }

        if(y+1 < 10) {
          if(!is_checked[x][y+1] && a[x][y+1] == 'o') {
            dq.emplace_back(x,y+1);
          }
        }

        if(y-1 >= 0) {
          if(!is_checked[x][y-1] && a[x][y-1] == 'o') {
            dq.emplace_back(x,y-1);
          }
        }
      }

      bool is_unite=true;
      for(int k=0;k<10;k++) {
        for(int l=0;l<10;l++) {
          if(!is_checked[k][l] && a[k][l] == 'o') is_unite = false;
        }
      }

      if(is_unite) {
        cout<<"YES\n";
        return 0;
      }
    }
  }

  cout<<"NO\n";
  return 0;
}