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

ll n;
vector< vector<ll> > G(n);
vector<ll> dpb,dpw;
vector<bool> check_b,check_w,check;

/*
int fb(int i);
int fw(int j);


int fb(int i) {
  if(check_b[i]) return dpb[i];
  check_b[i]=true;

  for(auto v:G[i]) {
    dpb[i]=(dpb[i]*fw(v))%mod;
  }

  return dpb[i];
}


int fw(int j) {
  if(check_w[j]) return dpw[j];
  check_w[j]=true;

  for(auto v:G[j]) {
    dpw[j]=(dpw[j]*(fw(v)+fb(v)))%mod;
  }

  return dpw[j];
}
*/

void f(int i, int root) {
  if(check[i]) return;
  check[i]=true;

  for(auto v:G[i]) {
    if(v == root) continue;

    f(v,i);
    dpb[i]=(dpb[i]*dpw[v])%mod;
    dpw[i]=(dpw[i]*(dpw[v]+dpb[v]))%mod;
  }

  return;
}

int main() {
  cin>>n;

  G=vector< vector<ll> >(n);

  ll x,y;
  rep(i,n-1) {
    cin>>x>>y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  // check_w=check_b=vector<bool>(n,false);
  check=vector<bool>(n,false);
  dpb=dpw=vector<ll>(n,1);

  f(0,-1);

/*
  rep(i,n) printf("%lld ", dpw[i]);
  cout<<endl;

  rep(i,n) printf("%lld ", dpb[i]);
  cout<<endl;
*/

  cout<<(dpb[0]+dpw[0])%mod<<endl;

  return 0;
}
