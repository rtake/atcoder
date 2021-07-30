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

int main() {
  int h,w,inf=999999999; cin>>h>>w;
  vector<string> s(h); rep(i,h) cin>>s[i];

  vector< vector<int> > d(h*w, vector<int>(h*w,inf));

  rep(i,h*w) {
    if(s[i/w][i%w] == '#') continue;

    d[i][i] = 0;
    // if(i-h >= 0 && s[(i-h)/w][i%w] == '.') d[i-h][i] = d[i][i-h] = 1;
    // if(i+h < h*w && s[(i+h)/w][i%w] == '.') d[i+h][i] = d[i][i+h] = 1;
    if(i-w >= 0 && s[(i-w)/w][i%w] == '.') d[i-w][i] = d[i][i-w] = 1;
    if(i+w < h*w && s[(i+w)/w][i%w] == '.') d[i+w][i] = d[i][i+w] = 1;
    if(i%w >= 1 && s[i/w][i%w-1] == '.') d[i][i-1] = d[i-1][i] = 1;
    if(i%w+1 <= w-1 && s[i/w][i%w+1] == '.') d[i][i+1] = d[i+1][i] = 1;
  }

  /*
  rep(i,h*w) {
    rep(j,h*w) printf("%d ", d[i][j]);
    cout<<endl;
  }
  */

  rep(k,h*w) {
    rep(i,h*w) {
      rep(j,h*w) {
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
        // ans=max(ans,d[i][j]);
      }
    }
  }

  int ans=0;
  rep(i,h*w) {
    rep(j,h*w) {
      if(d[i][j] == inf) continue;
      ans=max(ans,d[i][j]);
      // printf("%d ", d[i][j]);
    }
    // cout<<endl;
  }

  cout<<ans<<endl;
  return 0;
}