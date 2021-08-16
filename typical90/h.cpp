# include <bits/stdc++.h>
//# include <atcoder/all>

typedef long long lint;

using namespace std;
//using namespace atcoder;

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

// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }

int main() {
  lint n; cin>>n;
  string s; cin>>s;

  n=s.length();

  string atcoder="atcoder";
  vector< vector<lint> > dp(n, vector<lint>(7,0));

  // for(lint i=1;i<n;i++) {
  rep(i,n) {
    if(i == 0) {
      if(s[0] == atcoder[0]) dp[0][0]=1;
      continue;
    }

    rep(j,7) {
      dp[i][j] = dp[i-1][j];

      if(s[i] == atcoder[j]) {
        // if(j == 0) dp[i][0] = dp[i-1][0]+1;
        if(j == 0) dp[i][0]++;
        else dp[i][j] += dp[i-1][j-1];

        dp[i][j]%=mod;
      }

      // cout<<dp[i][j]<<" ";
    }

    // cout<<endl;
  }

  printf("%lld\n", dp[n-1][6]);

  return 0;
}
