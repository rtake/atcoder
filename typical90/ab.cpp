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
  lint n; cin>>n;
  vector<lint> lx(n),ly(n),rx(n),ry(n);
  rep(i,n) cin>>lx[i]>>ly[i]>>rx[i]>>ry[i];

  vector<lint> x(1002), xc(1001), y(1002), yc(1002);

  sort(lx.begin(), lx.end());
  sort(rx.begin(), rx.end());
  sort(ly.begin(), ly.end());
  sort(ry.begin(), ry.end());

  rep(i,n) {
    x[lx[i]]++;
    x[rx[i]]--;
    y[ly[i]]++;
    y[ry[i]]--;
  }
  
  xc[0]=x[0];
  yc[0]=y[0];
  for(lint i=1;i<=1000;i++) {
    xc[i]=xc[i-1]+x[i];
    yc[i]=yc[i-1]+y[i];
  }

  rep(i,10) cout<<xc[i]<<" ";
  cout<<endl;

  rep(i,10) cout<<yc[i]<<" ";
  cout<<endl;

  map<lint,lint> mp;
  rep(i,1001) rep(j,1001) mp[min(xc[i],yc[j])]++;

  for(lint k=1;k<=n;k++) cout<<mp[k]<<endl;

  return 0;
}
