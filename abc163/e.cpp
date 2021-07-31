# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint mod=1000000007;
lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

lint inv(lint x) {
  lint res=1, k=mod-2;
  while(k>0) {
    if(k&1 == 1) res=(res*x)%mod;
    x=(x*x)%mod;
    k/=2;
  }
  return res;
}

lint nCr_mod(lint n, lint k) {
  lint a=1,b=1;
  for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  for(int i=0;i<k;i++) b=(b*(k-i))%mod;
  return (a*inv(b))%mod;
}

int main() {
  lint inf=999999999,h,n; cin>>h>>n;
  vector<lint> a(n),b(n); rep(i,n) cin>>a[i]>>b[i];

  vector<lint> dp(h+1, inf);
  dp[h] = 0;

  // for(lint i=0;i<=h;i++) {
  for(lint i=h;i>=0;i--) {
    for(lint j=0;j<n;j++) {
      if(i-a[j] < 0) dp[0] = min(dp[i]+b[j], dp[0]);
      else dp[i-a[j]] = min(dp[i]+b[j], dp[i-a[j]]);

      // dp[i] = min(dp[i], dp[max(i-a[j],0LL)]+b[j]);
    }
  }

  printf("%lld\n", dp[0]);
  return 0;
}
