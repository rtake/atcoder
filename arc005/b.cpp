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
  int x,y; cin>>x>>y;
  string w; cin>>w;
  vector< vector<int> > c(10, vector<int>(1,-1));
  string s;
  for(int i=1;i<=9;i++) {
    cin>>s;
    for(auto x:s) c[i].push_back(x-'0');
  }

  for(int i=1;i<=4;i++) {
    cout << c[y][x];

    if(w[0] == 'R') {
      if(x == 9) { x--; w[0]='L'; }
      else x++;
    } else if(w[0] == 'L') {
      if(x == 1) { x++; w[0]='R'; }
      else x--;
    } 

    if(w[0] == 'U') {
      if(y == 1) { y++; w[0]='D'; }
      else y--;
    } else if(w[0] == 'D') {
      if(y == 9) { y--; w[0]='U'; }
      else y++;
    }
    
    if(w[1] == 'U') {
      if(y == 1) { y++; w[1]='D'; }
      else y--;
    } else if(w[1] == 'D') {
      if(y == 9) { y--; w[1]='U'; }
      else y++;
    }

  }

  cout << endl;
  return 0;
}
