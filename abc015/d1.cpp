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
  vector<lint> a(N),b(N); for(lint i=0;i<N;i++) cin>>a[i]>>b[i];

  vector<vector<lint>> dp(K+1, vector<lint>(W+1,0));

  for(int i=0;i<N;i++) {
    for(int k=K;k>=1;k--) {
      for(int w=1;w<=W;w++) {
        if(w-a[i] >= 0) {
          dp[k][w] = max(dp[k][w], dp[k-1][w-a[i]]+b[i]);
        }
      }
    }
  }

  printf("%lld\n", dp[K][W]);
  return 0;
}
