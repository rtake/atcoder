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
  int n;
  cin>>n;
  vector<ll> x(n),y(n),h(n);
  rep(i,n) cin>>x[i]>>y[i]>>h[i];

  vector<int> a;
  rep(i,n) {
    if(h[i] > 0) {
      a.push_back(i);
      if(a.size()>=2) break;
    }
  }

  vector< pair<ll,ll> > ans;
  rep(i,101) rep(j,101) {
    ll h0=h[a[0]]+abs(x[a[0]]-i)+abs(y[a[0]]-j);
    ll h1=h[a[1]]+abs(x[a[1]]-i)+abs(y[a[1]]-j);

    if(h0 == h1) ans.emplace_back(i,j);
  }

  // for(auto itr:ans) cout<<itr.first <<" "<<itr.second<<endl;

  for(auto itr:ans) {
    bool accept=true;
    ll x0=itr.first,y0=itr.second;
    ll h0=h[a[0]]+abs(x[a[0]]-x0)+abs(y[a[0]]-y0);

    rep(i,n) {
      accept=true;

      // cout<<h0<<" "<<max(h0-abs(x[i]-x0)-abs(y[i]-y0),0LL)<<endl;

      if(h[i] != max(h0-abs(x[i]-x0)-abs(y[i]-y0),0LL)) {
        accept=false;
        break;
      }
    }

    if(accept) {
      cout<<x0<<" "<<y0<<" "<<h0<<endl;
      return 0;
    }
  }

  return 0;
}
