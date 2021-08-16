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
  vector<lint> a(n),b(n); rep(i,n-1) cin>>a[i]>>b[i];

  vector< vector<lint> > G(n, vector<lint>(0));
  rep(i,n-1) {
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  rep(i,n) {
    // sort(G[i].begin(), G[i].end());
    sort(G[i].begin(), G[i].end(), greater<lint>());
  }

  vector<lint> path;
  vector<bool> is_arrived(n,false);
  vector<lint> v,w;
  bool is_leaf;

  is_arrived[0]=true;
  v.push_back(0);

  // while(!v.empty()) {
  while(true) {
    lint cur=v.back();
    v.pop_back();
    w.push_back(cur);
    path.push_back(cur);

    // cout<<cur<<endl;

    is_leaf=true;
    for(auto node:G[cur]) {
      // cout<<node<<endl;

      if(!is_arrived[node]) {
        is_arrived[node]=true;
        v.push_back(node);
        // path.push_back(node);
        is_leaf=false;
      }
    }

    // cout<<v[0]<<endl;
    // cout<<v.size()<<endl;

    

    if(is_leaf) {
      // cout<<"break"<<endl;
      if(cur == 0) break;
      // path.push_back(w.back());
      w.pop_back();
      v.push_back(w.back());
      w.pop_back();
    } 

    cout<<"\nv\n";
    for(auto x:v) cout<<x+1<<" ";
    cout<<endl;

    cout<<"w\n";
    for(auto x:w) cout<<x+1<<" ";
    cout<<endl;

    cout<<"path\n";
    for(auto x:path) printf("%lld ", x+1);
    cout<<endl<<endl;
  }

  /*
  for(auto x:path) printf("%lld ", x+1);
  cout<<endl;
  */

  return 0;
}
