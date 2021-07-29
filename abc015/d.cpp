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
  lint W,N,K; cin>>W>>N>>K;
  vector<lint> a(N+1),b(N+1); for(lint i=1;i<=N;i++) cin>>a[i]>>b[i];

  vector<vector<vector<lint>>> dp=vector<vector<vector<lint>>>(W+1,vector<vector<lint>>(K+1,vector<lint>(N+1,0)));

  for(int k=1;k<=N;k++) {
    for(int i=0;i<=W;i++) {
      for(int j=0;j<=K;j++) {
        if(i-a[k] >= 0) {
          if(j-1 >= 0) {
            dp[i][j][k] = max(dp[i-a[k]][j-1][k-1]+b[k], dp[i][j][k-1]);
          } else dp[i][j][k] = 0;
        } else dp[i][j][k] = dp[i][j][k-1];

        // printf("%d %d %d %lld\n", i, j, k, dp[i][j][k]);
      }
    }
  }

  printf("%lld\n", dp[W][K][N]);
  return 0;
}
