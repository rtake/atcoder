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

ll nCr_mod_memo[1010101];

void nCr_mod_init() {
  nCr_mod_memo[0]=1;
  for(ll i=1;i<1010101;i++) nCr_mod_memo[i]=(nCr_mod_memo[i-1]*i)%mod;
}

ll nCr_mod(lint n, lint k) {
  // lint a=1,b=1;
  // for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  // for(int i=0;i<k;i++) b=(b*(k-i))%mod;

  ll a=nCr_mod_memo[n];
  ll b=nCr_mod_memo[n-k];
  ll c=nCr_mod_memo[k];
  ll bc=(b*c)%mod;

  return (a*inv(bc))%mod;
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


vector<ll> dijkstra(vector< vector< pair<ll,ll> > > G, ll start) {
  ll n=G.size();
  vector<ll> d(n,1e18);
  priority_queue< pair<ll,ll>,
                  vector< pair<ll,ll> >,
                  greater< pair<ll,ll> > > Q;

  d[start]=0;
  Q.emplace(0,start);

  while(!Q.empty()) {
    auto u=Q.top();
    Q.pop();

    ll q_u=u.first;
    ll _u=u.second;

    if(d[_u] < q_u) continue;

    for(auto v:G[_u]) {
      ll c_v=v.first;
      ll _v=v.second;

      ll alt=q_u+c_v;

      if(alt < d[_v]) {
        d[_v]=alt;
        Q.emplace(alt,_v);
      }
    }
  }

  return d;
}

// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }


int main() {
  ll n,t;
  cin>>n>>t;
  vector<ll> a(n),b(n);
  rep(i,n) cin>>a[i]>>b[i];

  vector< pair<ll,ll> > v;
  rep(i,n) v.emplace_back(b[i],a[i]);

  // rep(i,n) v.emplace_back(-b[i],-a[i]);
  // sort(ALL(v));

  sort(ALL(v), greater< pair<ll,ll> >());

  // for(auto p:v) cout<<p.first<<" "<<p.second<<endl;

  ll max_b=0, sum_a=0, sum_b=0;
  auto maxpair=v[0];

  ll ans=maxpair.first;
  ll t_sum=maxpair.second;

  for(ll i=1;i<n;i++) {
    if(t_sum+v[i].second-maxpair.second >= t) {
      cout<<ans<<endl;
      return 0;
    } else {
      t_sum+=v[i].second;
      ans+=v[i].first;

      if(maxpair.second < v[i].second) {
        maxpair=v[i];
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
