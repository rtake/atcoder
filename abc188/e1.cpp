# include <bits/stdc++.h>
# include <atcoder/all>

typedef long long ll;

using namespace std;
using namespace atcoder;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

#ifdef LOCAL
#define dump(x) do{} while(0)
#endif

// ll gcd(ll x, ll y) { return (x==0)? y : gcd(y%x,x); }
// ll lcm(ll x, ll y) { return x/gcd(x,y)*y; }
ll P(ll n, ll k) { return (k==1) ? n : n*(P(n-1,k-1)); }

ll mod=1000000007;
ll comb[2000][2000];
ll nCr(ll n, ll r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  // if(comb[n][r]) return comb[n][r]%mod;
  if(comb[n][r]) return comb[n][r];
  // return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1));
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
  ll a=nCr_mod_memo[n], b=nCr_mod_memo[n-k], c=nCr_mod_memo[k];
  ll bc=(b*c)%mod;
  return (a*inv(bc))%mod;
}

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


ll n,m;
vector<bool> check;
vector<ll> a,b,c;
vector< vector<ll> > G,_G;


ll dfs_max(ll cur) {
  if(check[cur]) return b[cur];

  check[cur]=true;

  ll _max=-1e10;

  for(auto v:G[cur]) {
    _max=max(_max,max(dfs_max(v),a[v]));
  }

  return b[cur]=_max;
}


ll dfs_min(ll cur) {
  if(check[cur]) return c[cur];

  check[cur]=true;

  ll _min=a[cur];

  for(auto v:_G[cur]) {
    // _min=min(_min,min(dfs_min(v),a[v]));
    _min=min(_min,dfs_min(v));
  }

  return c[cur]=_min;
}


int main() {
  cin>>n>>m;
  a=b=c=vector<ll>(n);
  rep(i,n) cin>>a[i];
  
  G=_G=vector< vector<ll> >(n);

  ll x,y;
  rep(i,m) {
    cin>>x>>y;
    x--,y--;
    G[x].push_back(y);
    _G[y].push_back(x);
  }

  check=vector<bool>(n,false);

  rep(i,n) {
    if(check[i]) continue;
    dfs_max(i);
  }


  check=vector<bool>(n,false);

  rep(i,n) {
    if(check[i]) continue;
    dfs_min(i);
  }


/*
  for(auto i:b) cout<<i<<" "; cout<<endl;
  for(auto i:c) cout<<i<<" "; cout<<endl;
*/


  ll ans=-1e18;

  rep(i,n) ans=max(ans,b[i]-c[i]);

  cout<<ans<<endl;

  return 0;
}
