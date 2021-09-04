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

// vector< pair<ll, pair<ll,ll> > > E[101010];

int main() {
  ll n,m,x,y;
  cin>>n>>m>>x>>y;

  // vector< vector< tuple<ll,ll,ll> > > E(n+1);
  // vector< pair<ll, pair<ll,ll> > > E[n+1];
  vector< vector< pair<ll, pair<ll,ll> > > > E(n+1);

  ll a,b,t,k;
  rep(i,m) {
    cin>>a>>b>>t>>k;
    auto p=make_pair(t,k);
    E[a].emplace_back(b,p);
    // E[a].push_back({b,{t,k}});
    E[b].emplace_back(a,p);
  }

  ll inf=1e18;
  vector<ll> d(n+1,inf);
  vector<bool> is_checked(n+1,false);
  priority_queue< pair<ll,ll>,
                  vector< pair<ll,ll> >,
                  greater< pair<ll,ll> > > pq;

  d[x]=0;
  pq.push(make_pair(d[x],x));

  while(!pq.empty()) {
    auto p0=pq.top();
    pq.pop();

    ll dist=p0.first, cur=p0.second;
 
    if(is_checked[cur]) continue;
    else is_checked[cur]=true;

    for(auto next:E[cur]) {
      ll pos=next.first;
      ll t_=next.second.first;
      ll k_=next.second.second;
      ll alt=(dist+k_-1)/k_*k_+t_;

      if(d[pos]>alt) {
        d[pos]=alt;
        pq.push({d[pos],pos});
      }
    }
  }

  if(d[y] == inf) cout<<-1<<endl;
  else cout<<d[y]<<endl;

  return 0;
}
