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
  int n; cin>>n;

  if(n%2 != 0 || n == 0) {
    cout<<endl;
    return 0;
  } 

  vector< set<string> > vs(100);
  vs[2].insert("()");

  for(int i=2;i+2<=n;i+=2) {

    for(auto x:vs[i]) {
      vs[i*2].insert(x+x);
      vs[i+2].insert("()"+x);
      vs[i+2].insert(x+"()");
      vs[i+2].insert("("+x+")");
    }

  }

  for(int i=2;i+2<=n;i+=2) {
    for(auto x:vs[i]) {
      for(auto y:vs[n-i]) {
        vs[n].insert(x+y);
      }
    }
  }

  for(auto x:vs[n]) cout<<x<<endl;

  return 0;
}
