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
  int h,w,q; cin>>h>>w>>q;

  UnionFind tree(h*w);
  vector<bool> is_red(h*w,false);

  rep(i,q) {
    int k; cin>>k;

    if(k == 1) {
      int r,c; cin>>r>>c;
      r--;
      c--;
      is_red[r*w+c]=true;

      if(r-1>=0 && is_red[(r-1)*w+c]) tree.unite(r*w+c, (r-1)*w+c);
      if(r+1<h && is_red[(r+1)*w+c]) tree.unite(r*w+c, (r+1)*w+c);
      if(c-1>=0 && is_red[r*w+c-1]) tree.unite(r*w+c, r*w+c-1);
      if(c+1<w && is_red[r*w+c+1]) tree.unite(r*w+c, r*w+c+1);

      // rep(i,h*w) cout<<tree.root(i)<<" ";
      // cout<<endl;

    } else if(k == 2) {
      int ra,ca,rb,cb; cin>>ra>>ca>>rb>>cb;
      ra--;
      ca--;
      rb--;
      cb--;

      if(is_red[ra*w+ca] && is_red[rb*w+cb] && tree.same(ra*w+ca,rb*w+cb)) {
        cout<<"Yes\n";
      } else cout<<"No\n";
    }

  }

  return 0;
}
