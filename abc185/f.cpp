# include <bits/stdc++.h>
# include <atcoder/all>

typedef long long lint;

using namespace std;
using namespace atcoder;

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

lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }

int main() {
  lint n,q; cin>>n>>q;
  vector<lint> a(n); rep(i,n) cin>>a[i];
  vector<lint> t(q),x(q),y(q); 
  rep(i,q) {
    cin>>t[i]>>x[i]>>y[i];
    //x[i]--;
    //y[i]--;
  }

  segtree<lint, op, e> seg(a);

  rep(i,q) {
    if(t[i] == 1) {
      lint v=seg.get(x[i]-1);
      v^=y[i];
      seg.set(x[i]-1,v);
    } else {
      cout<<seg.prod(x[i]-1,y[i])<<endl;
    }
  }

  return 0;
}
