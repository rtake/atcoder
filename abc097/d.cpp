# include <bits/stdc++.h>
// # include <atcoder/all>

typedef long long ll;

using namespace std;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)
#define ALL(a)  (a).begin(),(a).end()

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


int main() {
  int n,m;
  cin>>n>>m;
  vector<int> p(n),x(m),y(m);
  rep(i,n) cin>>p[i],p[i]--;
  rep(i,m) cin>>x[i]>>y[i],x[i]--,y[i]--;

  UnionFind uf(n),_uf(n);

  rep(i,m) {
    uf.unite(x[i],y[i]);
    _uf.unite(p[x[i]],p[y[i]]);
  }

  int ans=0;
  rep(i,n) {
    if(_uf.find(p[i]) == _uf.find(i)) ans++;
  }

  cout<<ans<<endl;
  return 0;
}
