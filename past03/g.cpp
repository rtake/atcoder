# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

lint C(lint n, lint k) {
  if(n == k) { return 1; }
  else if(n < k) { return 0; }
  else if(k == 0) { return 1; }
  else if(k == 1) { return n; }
  else return C(n-1,k-1) + C(n-1,k);
}

lint P(lint n, lint k) {
  if(k == 1) { return n; }
  return (n*(P(n-1,k-1)%1000000007)%1000000007);
}


int main() {
  int N,X,Y; cin >> N >> X >> Y;
  X+=200; Y+=200;
  
  vector< vector<int> > m(401,vector<int>(401,99999));
  //int m[401][401];
  m[200][200] = 0;

  for(int i=0;i<N;i++) {
    int x,y; cin >> x >> y;
    m[x+200][y+200] = -1;
  }

  deque< pair<int,int> > q;
  q.push_back(make_pair(200,200));

  while((int)q.size()>0) {
    pair<int,int> p = q.front();
    q.pop_front();

    if(m[p.first][p.second] != -1) {
      if(p.first+1 <= 400 && p.second+1 <= 400 && m[p.first+1][p.second+1] > 9999) {
        q.push_back(make_pair(p.first+1,p.second+1));
        m[p.first+1][p.second+1] = min(m[p.first+1][p.second+1],m[p.first][p.second]+1);
      }
      if(p.second+1 <= 400 && m[p.first][p.second+1] > 0) {
        q.push_back(make_pair(p.first,p.second+1));
        m[p.first][p.second+1] = min(m[p.first][p.second+1],m[p.first][p.second]+1);
      }
      if(0 <= p.first-1 && p.second+1 <= 400 && m[p.first-1][p.second+1] > 9999) {
        q.push_back(make_pair(p.first-1,p.second+1));
        m[p.first-1][p.second+1] = min(m[p.first-1][p.second+1],m[p.first][p.second]+1);
      }
      if(p.first+1 <= 400 && m[p.first+1][p.second] > 9999) {
        q.push_back(make_pair(p.first+1,p.second));
        m[p.first+1][p.second] = min(m[p.first+1][p.second],m[p.first][p.second]+1);
      }
      if(0 <= p.first-1 && m[p.first-1][p.second] > 9999) {
        q.push_back(make_pair(p.first-1,p.second));
        m[p.first-1][p.second] = min(m[p.first-1][p.second],m[p.first][p.second]+1);
      }
      if(0 <= p.second-1 && m[p.first][p.second-1] > 9999) {
        q.push_back(make_pair(p.first,p.second-1));
        m[p.first][p.second-1] = min(m[p.first][p.second-1],m[p.first][p.second]+1);
      }
    }

    //printf("%d %d %d\n",p.first,p.second,m[p.first][p.second]);

    

  }

  cout << m[X][Y] << endl;
  return 0;
}
