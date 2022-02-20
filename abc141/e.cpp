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
  string s;
  cin>>n>>s;

  ll ans=0;
  vector< vector<ll> > dp;

  for(ll i=1;i<n;i++) {
    string _s=s.substr(0,i), _t=s.substr(i,n-i);

    // length of LCS(_s,_t)
    dp=vector< vector<ll> >(i+1, vector<ll>(n-i+1,0));

    for(ll j=0;j<i;j++) {
      for(ll k=0;k<n-i;k++) {
        if(j > 0 && k > 0) {
          if(_s[j] == _t[k]) dp[j][k]=dp[j-1][k-1]+1;
          else dp[j][k]=max(dp[j-1][k],dp[j][k-1]);
        } else {
          if(_s[j] == _t[k]) dp[j][k]=1;
        }
      }
    }

    ans=max(ans,dp[i-1][n-i-1]);

/*
    cout<<_s<<" "<<_t<<endl;
    for(ll j=1;j<=i;j++) {
      for(ll k=1;k<=n-i;k++) cout<<dp[j][k]<<" ";
      cout<<endl;
    } 

    cout<<ans<<endl<<endl;
*/

  }

  cout<<ans<<endl;

  return 0;
}
