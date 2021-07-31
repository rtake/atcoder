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
  lint k; cin>>k;
  vector< vector<lint> > dp(1, vector<lint>(10,1));

  bool is_found=false;
  lint cur=0;
  vector<lint> d(10), a;
  for(lint i=1;;i++) {
    for(int j=0;j<=9;j++) {
      if(j == 0) d[0] = dp[i-1][0] + dp[i-1][1];
      else if(j == 9) d[9] = dp[i-1][8] + dp[i-1][9];
      else d[j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];

      cur+=d[j];

      if(cur>=k) {
        cur-=d[j];
        a.push_back((j-1)%10);

        return 0;
      }
    }

    dp.push_back(d);
  }

  return 0;
}
