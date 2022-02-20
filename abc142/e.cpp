# include <bits/stdc++.h>
// # include <atcoder/all>

typedef long long ll;

using namespace std;
// using namespace atcoder;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)
#define ALL(a)  (a).begin(),(a).end()

ll mod=1e9+7;
ll INF=1e18;

ll gcd(ll x, ll y) { return (x==0)? y : gcd(y%x,x); }
ll lcm(ll x, ll y) { return x/gcd(x,y)*y; }
ll P(ll n, ll k) { return (k==1) ? n : n*(P(n-1,k-1)); }

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


int main() {
  ll n,m;
  cin>>n>>m;
  vector<ll> a(m+1),b(m+1);
  vector< vector<ll> > c(m+1);

  rep(i,m) {
    cin>>a[i+1]>>b[i+1];
    c[i+1]=vector<ll>(b[i+1]);
    rep(j,b[i+1]) cin>>c[i+1][j];
  }

  vector< vector<ll> > dp(m+2, vector<ll>(1<<n+1,INF));

  for(ll i=1;i<=m;i++) {
    dp[i][0]=0;

    ll S=0;
    rep(j,b[i]) S|=1<<(c[i][j]-1);
    // cout<<"S "<<S<<endl;

    for(ll bit=0;bit<(1<<n);bit++) {
      dp[i][bit]=min(dp[i][bit],dp[i-1][bit]);

      if(bit == S) continue;
      dp[i][bit|S]=min(dp[i][bit|S],dp[i][bit]+a[i]);
      // dp[i+1][bit|S]=min(dp[i][bit|S],dp[i+1][bit]);
    }
  }

/*
  for(ll i=1;i<=m;i++) {
    for(ll bit=0;bit<(1<<n);bit++) cout<<dp[i][bit]<<" ";
    cout<<endl;
  }
*/

  ll ans=dp[m][(1<<n)-1];
  if(ans == INF) ans=-1;
  cout<<ans<<endl;

  return 0;
}
