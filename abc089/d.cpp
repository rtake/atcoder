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
  int h,w,d;
  cin>>h>>w>>d;
  vector< vector<ll> > a(h,vector<ll>(w));
  rep(i,h) rep(j,w) cin>>a[i][j];

  map<ll,pair<ll,ll> > mp;
  rep(i,h) rep(j,w) mp[a[i][j]]=make_pair(i+1,j+1);

  /*
  vector< vector<ll> > dmat(h*w+1,vector<ll>(h*w+1,0));

  for(ll i=1;i<=h*w;i++) {
    for(ll j=1;j<=h*w;j++) {
      auto p0=mp[i],p1=mp[j];
      ll x0=p0.first, y0=p0.second;
      ll x1=p1.first, y1=p1.second;

      cout<<x0<<" "<<y0<<" ";
      cout<<x1<<" "<<y1<<" ";
      cout<<abs(x0-x1)+abs(y0-y1)<<endl;

      dmat[i][j]=abs(x0-x1)+abs(y0-y1);
      // cout<<dmat[i][j]<<" ";
    }
    // cout<<endl;
  }
  */

  // for(ll i=1;i<=h*w;i++) cout<<mp[i].first<<" "<<mp[i].second<<endl;

  ll q,l,r;
  cin>>q;
  rep(i,q) {
    cin>>l>>r;

    ll cost=0;
    for(ll i=l;i+d<=r;i+=d) {
      // cout<<i<<" "<<i+d<<" "<<dmat[i][i+d]<<endl;
      // cost+=dmat[i][i+d];

      auto p0=mp[i],p1=mp[i+d];
      ll x0=p0.first, y0=p0.second;
      ll x1=p1.first, y1=p1.second;
      cost+=abs(x0-x1)+abs(y0-y1);
    }

    cout<<cost<<endl;
  }

  return 0;
}
