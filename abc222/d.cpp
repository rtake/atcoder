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
  ll n;
  cin>>n;
  vector<ll> a(n),b(n);
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];

  mod=998244353;

  vector< vector<ll> > dp(n, vector<ll>(3010,0));

  for(ll j=a[0];j<=b[0];j++) dp[0][j]=1;
  // for(ll j=0;j<=20;j++) cout<<dp[0][j]<<" ";
  // cout<<endl;

  for(ll i=1;i<n;i++) {
    for(ll j=0;j<=b[i];j++) {
      if(j == 0) dp[i][0]=dp[i-1][0];
      else dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
    }

    for(ll j=0;j<a[i];j++) dp[i][j]=0;

    // for(ll j=0;j<=20;j++) cout<<dp[i][j]<<" ";
    // cout<<endl;
  }

  ll ans=0;
  for(ll j=0;j<=3000;j++) ans=(ans+dp[n-1][j])%mod;

  cout<<ans<<endl;

  return 0;
}
