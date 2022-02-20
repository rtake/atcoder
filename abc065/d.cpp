# include <bits/stdc++.h>
// # include <atcoder/all>

typedef long long ll;

using namespace std;
// using namespace atcoder;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)
#define ALL(a)  (a).begin(),(a).end()

ll gcd(ll x, ll y) { return (x==0)? y : gcd(y%x,x); }
ll lcm(ll x, ll y) { return x/gcd(x,y)*y; }
ll P(ll n, ll k) { return (k==1) ? n : n*(P(n-1,k-1)); }

ll mod=1000000007;
ll comb[2000][2000];
ll nCr(ll n, ll r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

ll inv(ll x) {
  ll res=1, k=mod-2;
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

ll nCr_mod(ll n, ll k) {
  // ll a=1,b=1;
  // for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  // for(int i=0;i<k;i++) b=(b*(k-i))%mod;

  ll a=nCr_mod_memo[n];
  ll b=nCr_mod_memo[n-k];
  ll c=nCr_mod_memo[k];
  ll bc=(b*c)%mod;

  return (a*inv(bc))%mod;
}


/*
ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}
*/


ll binpower(ll a, ll b, ll m) {
  ll ans=1;

  a%=m;

  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%m;
    a=(a*a)%m;
    b/=2;
  }
  return ans;
}


bool judgeIentersected
(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy) {

  ll ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  ll tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  ll tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  ll td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

  return tc * td < 0 && ta * tb < 0;
  // return tc * td <= 0 && ta * tb <= 0; // 端点を含む場合
};


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
  ll n;
  cin>>n;

  vector< pair< pair<ll,ll>,ll> > xy(n);
  vector< pair<ll,pair<ll,ll> > > v;

  UnionFind uf(n);

  ll x,y;
  rep(i,n) {
    cin>>x>>y;
    xy[i].first=make_pair(x,y);
    xy[i].second=i;
  }

  sort(ALL(xy));

  rep(i,n-1) {
    auto p0=xy[i].first;
    auto p1=xy[i+1].first;

    v.emplace_back\
     (p1.first-p0.first, make_pair(xy[i].second,xy[i+1].second));

    // cout<<p0.first<<" "<<p0.second<<endl;
    // cout<<xy[i].second<<endl;
  }

  rep(i,n) {
    auto p=xy[i].first;
    swap(p.first,p.second);
    xy[i].first=p;
  }

  sort(ALL(xy));

///*
  rep(i,n-1) {
    auto p0=xy[i].first;
    auto p1=xy[i+1].first;
    v.emplace_back\
     (p1.first-p0.first, make_pair(xy[i].second,xy[i+1].second));
     // (p1.second-p0.second, make_pair(xy[i].second,xy[i+1].second));
     // (p0.second-p1.second, make_pair(p0.second,p1.second));

    // cout<<p0.first<<" "<<p0.second<<endl;
    // cout<<xy[i].second<<endl;
  }
//*/

  // sort(ALL(v), greater< pair<ll, pair<ll,ll>> >());
  sort(ALL(v));

/*
  rep(i,(ll)v.size()) {
    auto p=v[i].second;
    printf("%lld %lld %lld\n", v[i].first, p.first, p.second);
  }
*/

///*
  ll ans=0;

  for(ll i=0;i<n*2;i++) {
    auto p=v[i].second;

    if(uf.find(p.first) != uf.find(p.second)) {
      uf.unite(p.first,p.second);
      ans+=v[i].first;
    }

    if(uf.size(p.first) == n || uf.size(p.second) == n) break;
  }

  cout<<ans<<endl;
//*/

  return 0;
}
