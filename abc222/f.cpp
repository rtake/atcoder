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


ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}


ll n;
vector<ll> a,b,c,d,w;
vector< vector< pair<ll,ll> > > G;

void dfs(ll c, ll p) {
  ll next=-1,cost=-1;

  for(auto v:G[c]) {
    if(v.second == p) continue;

    ll alt=v.first+d[v.second];
    if(alt > cost) {
      cost=alt;
      next=v.second;
    }
  }

  dfs(next,c);

  for(auto v:G[c]) {
    if(v.second == p || v.second == next) continue;

    w[v.second]=w[next]+v.first;
  }
}

int main() {
  cin>>n;
  a=b=c=d=w=vector<ll>(n,-1);

  rep(i,n-1) cin>>a[i]>>b[i]>>c[i];
  rep(i,n) cin>>d[i];

  G=vector< vector< pair<ll,ll> > >(n);

  rep(i,n-1) {
    a[i]--, b[i]--;
    G[a[i]].emplace_back(c[i],b[i]);
    G[b[i]].emplace_back(c[i],a[i]);
  }

  ll root=-1;
  rep(i,n) {
    if(G[i].size() == 1) {
      root=i;
      break;
    }
  }

  dfs(root,-1);

  return 0;
}
