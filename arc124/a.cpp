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
  lint mod=998244353, n,k; cin>>n>>k;
  vector<char> c(k);
  vector<lint> m(k);
  rep(i,k) cin>>c[i]>>m[i];

  vector<lint> a(n,0);
  vector<bool> is_bound(n,false);

  rep(i,k) {
    rep(j,n) {
      if(m[i]-1 == j) {
        a[j]=1;
        is_bound[j]=true;
      } else if(m[i]-1 < j) {
        if(c[i] == 'L') a[j]++;
      } else if(m[i]-1 > j) {
        if(c[i] == 'R') a[j]++;
      }
    }
  }

  lint ans=1;
  rep(i,n) {
    if(is_bound[i]) continue;
    ans = (ans*a[i])%mod;
  }

  printf("%lld\n", ans);
  return 0;
}
