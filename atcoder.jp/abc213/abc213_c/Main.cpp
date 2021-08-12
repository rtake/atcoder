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

int main() {
  lint h,w,n; cin>>h>>w>>n;
  vector< pair<lint,lint> > a(n),b(n);

  rep(i,n) {
    cin>>a[i].first>>b[i].first;
    a[i].second=i;
    b[i].second=i;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector< vector<lint> > ans(n,vector<lint>(2));

  lint cnt=1;
  ans[a[0].second][0]=cnt;

  for(lint i=1;i<n;i++) {
    if(a[i].first > a[i-1].first) cnt++;
    ans[a[i].second][0]=cnt;
  }

  cnt=1;
  ans[b[0].second][1]=cnt;

  for(lint i=1;i<n;i++) {
    if(b[i].first > b[i-1].first) cnt++;
    ans[b[i].second][1]=cnt;
  }

  rep(i,n) printf("%lld %lld\n", ans[i][0], ans[i][1]);

  return 0;
}