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
  vector<int> a(n-1),b(n-1);
  rep(i,n-1) cin>>a[i]>>b[i];
  rep(i,n-1) {
    a[i]--;
    b[i]--;
  }

  vector< vector<int> > G(n);
  rep(i,n-1) {
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  int ncolor=0;
  rep(i,n) ncolor=max(ncolor,(int)G[i].size());

  vector<bool> is_arrived(n,false);
  vector<int> c(n,0);
  map< pair<int,int>, int> mp;
  deque<int> dq;

  dq.push_back(0);
  is_arrived[0]=true;

  while(!dq.empty()) {
    int cur=dq.front();
    dq.pop_front();

    // rep(i,n) cout<<c[i]<<" ";
    // cout<<endl;

    for(auto next:G[cur]) {
      if(is_arrived[next]) continue;
      mp[pair<int,int>(min(cur,next),max(cur,next))]=c[cur]+1;

      c[cur]=(c[cur]+1)%ncolor;
      c[next]=c[cur];

      dq.push_back(next);
      is_arrived[next]=true;
    }

    // rep(i,n) cout<<c[i]<<" ";
    // cout<<endl;
  }

  cout<<ncolor<<endl;
  rep(i,n-1) cout<<mp[pair<int,int>(a[i],b[i])]<<endl;

  return 0;
}
