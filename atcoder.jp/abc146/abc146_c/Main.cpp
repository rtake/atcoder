# include <bits/stdc++.h>
//# include <atcoder/all>

typedef long long lint;
typedef long long ll;

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

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

ll a;
ll b;

ll d(ll n) {
  stringstream ss;
  ss<<n;
  return ss.str().length();
}

ll cost(ll n) { return a*n+b*d(n); }

int main() {
  // ll a,b,x;
  ll x;
  cin>>a>>b>>x;

  ll pow9=1000000000, inf=99999999999999;
  ll l=0,r=pow9,m;
  r=pow9+1;

  m=(l+r)/2;

  if(cost(pow9) <= x) {
    printf("%lld\n", pow9);
    return 0;
  } else if(x < cost(1)) {
    cout<<0<<endl;
    return 0;
  }

  while(l<r) {
    if(cost(m) <= x) {
      if(x < cost(m+1)) {
        printf("%lld\n", m);
        return 0;
      } else {
        l=m;
      }
    } else if(x < cost(m)) {
      r=m;
    }

    m=(l+r)/2;
  }

  return 0;
}