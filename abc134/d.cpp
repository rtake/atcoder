# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

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
  lint n; cin>>n;
  vector<int> a(n+1); rep(i,n) cin>>a[i+1];

  vector<int> b(n+1,0), c(n+1,0);
  for(int i=n;i>=1;i--) {
    if(c[i]%2 != a[i]) b[i]=1;
    for(int j=1;j*j<=i;j++) {
      if(i%j == 0) {
        c[j]+=b[i];
        if(i/j != j) c[i/j]+=b[i];
      }
    }
  }

  vector<int> d(0);
  rep(i,n) if(b[i+1]==1) d.push_back(i+1);
  
  printf("%d\n", (int)d.size());
  for(auto x:d) printf("%d ", x);
  if((int)d.size()>0) cout<<endl;

  return 0;
}
