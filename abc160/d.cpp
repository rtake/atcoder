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
  int inf=999999999,n,x,y; cin>>n>>x>>y;
  x--; y--;

  vector< vector<int> > d(n, vector<int>(n,inf));
  rep(i,n) d[i][i] = 0;
  rep(i,n-1) d[i][i+1] = d[i+1][i] = 1;
  d[x][y] = d[y][x] = 1;

  rep(k,n) {
    rep(i,n) {
      rep(j,n) {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

  /*
  rep(i,n) {
    rep(j,n) cout<<d[i][j];
    cout<<endl;
  }
  */

  map<lint,int> mp;
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      mp[d[i][j]]++;
    }
  }

  rep(i,n-1) cout<<mp[i+1]<<endl;
  return 0;
}
