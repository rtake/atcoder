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
  lint u,v,inf=9999999999,n,m,k; cin>>n>>m>>k;
  mod=998244353;

  vector< vector<lint> > d(n, vector<lint>(n,1));
  rep(i,m) {
    cin>>u>>v;
    d[u-1][v-1] = d[v-1][u-1] = inf;
  }

  vector< map<lint,lint> > vmp(n);
  deque<lint> dq;
  dq.push_back(0);

  lint cur=0;
  for(int i=1;i<n;i++) {
    cur=dq.front();
    dq.pop_front();
  
    for(int j=0;j<n;j++) {
      if(cur == j) continue;
      if(d[cur][j] == 1) {
        vmp[j][i]++;
        dq.push_back(j);
      }
    }

  }

  lint ans=1;
  rep(i,n) {
    for(int j=1;j<k;j++) {
      ans *= vmp[i][k-j];
      ans %= mod;
    }
  }

  /*
  vector< vector<lint> > dp(k, vector<lint>(n,0));
  dp[0][0]=1;
  for(int i=1;i<k;i++) {
    rep(j,n) {
      dp[i][j] 

    }
  }
  */

  printf("%lld\n", ans);

  return 0;
}
