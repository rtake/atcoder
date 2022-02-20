# include <bits/stdc++.h>
// # include <atcoder/all>

typedef long long lint;
typedef long long ll;

using namespace std;
// using namespace atcoder;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)
#define ALL(a)  (a).begin(),(a).end()

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


/*
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
*/


// https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
struct UnionFind {
  vector<ll> data; // store root | (-size)
 
  UnionFind(ll sz) { data.assign(sz, -1); }
 
  bool unite(ll x, ll y) {
    x=find(x);
    y=find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x,y);
    data[x] += data[y]; // size
    data[y] = x; // root
    return true;
  }
 
  int find(int k) {
    if(data[k] < 0) return k;
    return data[k]=find(data[k]);
  }
 
  int size(int k) { return (-data[find(k)]); }
};


ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}


// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }


int main() {
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s[i];

  vector< vector<int> > l,r,u,d;
  l=r=u=d=vector< vector<int> >(h,vector<int>(w,-1));

  rep(i,h) {
    if(s[i][0] == '#') l[i][0]=0;
    if(s[i][w-1] == '#') r[i][w-1]=w-1;
    else r[i][w-1]=w;

    for(int j=1;j<w;j++) {
      l[i][j]=l[i][j-1];
      if(s[i][j] == '#') l[i][j]=j;
    }

    for(int j=w-2;j>=0;j--) {
      r[i][j]=r[i][j+1];
      if(s[i][j] == '#') r[i][j]=j;
    }
  }

  rep(i,w) {
    if(s[0][i] == '#') u[0][i]=0;
    if(s[h-1][i] == '#') d[h-1][i]=h-1;
    else d[h-1][i]=h;

    for(int j=1;j<h;j++) {
      u[j][i]=u[j-1][i];
      if(s[j][i] == '#') u[j][i]=j;
    }

    for(int j=h-2;j>=0;j--) {
      d[j][i]=d[j+1][i];
      if(s[j][i] == '#') d[j][i]=j;
    }
  }

/*
  rep(i,h) {
    rep(j,w) cout<<u[i][j]<<" ";
    cout<<endl;
  }

  cout<<endl;

  rep(i,h) {
    rep(j,w) cout<<d[i][j]<<" ";
    cout<<endl;
  }
*/

  int ans=0;
  rep(i,h) rep(j,w) {
    if(s[i][j] == '#') continue;
    ans=max(ans,r[i][j]-l[i][j]-1+d[i][j]-u[i][j]-1-1);
  }

  cout<<ans<<endl;

  return 0;
}
