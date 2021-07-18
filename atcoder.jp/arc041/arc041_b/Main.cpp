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
  int n,m; cin>>n>>m;
  vector<string> a(n); for(int i=0;i<n;i++) cin>>a[i];
  vector< vector<int> > b(n, vector<int>(0));
  for(int i=0;i<n;i++) for(auto c:a[i]) b[i].push_back(c-'0');

  vector< vector<int> > c(n, vector<int>(m,0));
  for(int i=1;i<n-1;i++) {
    for(int j=1;j<m-1;j++) {
      int num=min(min(b[i+1][j], b[i-1][j]), min(b[i][j+1], b[i][j-1]));
      b[i+1][j]-=num;
      b[i-1][j]-=num;
      b[i][j+1]-=num;
      b[i][j-1]-=num;
      c[i][j] += num;
    }
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) cout<<c[i][j];
    cout<<endl;
  }

  return 0;
}