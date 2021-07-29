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
  lint n,m; cin>>n>>m;
  vector<lint> a(m),b(m); rep(i,m) cin>>a[i]>>b[i];

  vector<lint> c(n,0), d(n,0);
  rep(i,n) {
    a[i]--; c[a[i]]++;
    b[i]--; c[b[i]]--;
  } 

  d[0]=c[0];
  rep(i,n-1) d[i+1]=d[i]+c[i+1];

  return 0;
}
