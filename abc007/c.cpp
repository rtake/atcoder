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
  int r,c; cin>>r>>c;
  vector<int> s(2),g(2); cin>>s[0]>>s[1]>>g[0]>>g[1];
  char m[r][c]; for(int i=0;i<r;i++) cin>>m[i];

  int inf=99999999;
  vector< vector<int> > a(r, vector<int>(c,inf));
  deque< pair<int,int> > dq;

  dq.emplace_back(s[0]-1,s[1]-1);
  a[s[0]-1][s[1]-1] = 0;

  while(!dq.empty()) {
    auto cur=dq.front();
    if(cur.first == g[0]-1 && cur.second == g[1]-1) break;

    int x=cur.first, y=cur.second;
    int depth=a[x][y];
    dq.pop_front();

    if(m[x+1][y] == '.' && a[x+1][y] == inf) {
      a[x+1][y] = min(a[x+1][y], depth+1);
      dq.emplace_back(x+1, y);
    }
    if(m[x-1][y] == '.' && a[x-1][y] == inf) {
      a[x-1][y] = min(a[x-1][y], depth+1);
      dq.emplace_back(x-1, y);
    }
    if(m[x][y+1] == '.' && a[x][y+1] == inf) {
      a[x][y+1] = min(a[x][y+1], depth+1);
      dq.emplace_back(x, y+1);
    }
    if(m[x][y-1] == '.' && a[x][y-1] == inf) { 
      a[x][y-1] = min(a[x][y-1], depth+1);
      dq.emplace_back(x, y-1);
    }
  }

  cout<<a[g[0]-1][g[1]-1]<<endl;
  return 0;
}
