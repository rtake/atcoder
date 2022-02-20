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


int main() {
  ll n,k;
  cin>>n>>k;
  vector<ll> w(n+1),p(n+1);
  rep(i,n) cin>>w[i+1]>>p[i+1];

  vector< vector< pair<ll,ll> > > \
   dp(n+1,vector< pair<ll,ll> >(n+1,pair<ll,ll>(1e9,0)));

  // dp[1][1]=make_pair(w[0],(p[0]/100)*w[0]);

  for(ll i=1;i<=n;i++) {

    if(dp[i-1][1].second*(dp[i-1][1].first+w[i]) < (dp[i-1][1].second+w[i]*p[i])*dp[i-1][1].first) {
      dp[i][1]=make_pair(w[i],w[i]*p[i]);
    } else {
      dp[i][1]=dp[i-1][1];
    }

    for(ll j=2;j<=i;j++) {
      dp[i][j]=dp[i][j-1];

      // if(dp[i][j].second/dp[i][j].first < (dp[i][j].second+w[i]*p[i])/(dp[i][j].first+w[i])) {
      if(dp[i][j].second*(dp[i][j].first+w[i]) < (dp[i][j].second+w[i]*p[i])*dp[i][j].first) {
        // printf("%lld %lld %lld %lld\n", dp[i][j].first, dp[i][j].second, w[i], p[i]);
        // printf("%lld < %lld\n", dp[i][j].second*(dp[i][j].first+w[i]), (dp[i][j].second+w[i]*p[i])*dp[i][j].first);
        dp[i][j].first+=w[i]; // total
        dp[i][j].second+=w[i]*p[i]; // salt
      }
    }

    for(ll j=1;j<=n;j++) printf("%lld(%lld) ",dp[i][j].first,dp[i][j].second);
    cout<<endl;
  } // for i-th salty-water

  printf("%.12lf\n", (double)dp[n][k].second/dp[n][k].first);

  return 0;
}
