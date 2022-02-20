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
vector<ll> a,b;

bool isok(ll m) {

  // b[0]=2*m;
  // b[1]=2*(a[0]-m);
  // b[2]=2*(a[1]-b[1]/2);
  // ...
  // b[n-1]=2*(a[n-2]-b[n-2]);

  b[1]=2*(a[0]-m);

  if(b[1] < 0) return false;

  for(ll i=2;i<n;i++) {
    b[i]=2*(a[i-1]-b[i-1]/2);

    if(b[i] < 0) {
      return false;
    }
  }

  b[0]=2*(a[n-1]-b[n-1]/2);

  // rep(i,n) cout<<b[i]<<" "; cout<<endl;

  if(b[0] < 2*m) return false;
  else return true;
} 


int main() {
  cin>>n;
  a=b=vector<ll>(n);
  rep(i,n) cin>>a[i];

  ll ng=1e18,ok=0;
  while(abs(ok-ng) > 1) {
    ll m=(ok+ng)/2;
    if(isok(m)) ok=m;
    else ng=m;

    // cout<<"ok "<<ok<<" ng "<<ng<<endl;
  }

  // cout<<"ok "<<ok<<endl;

  b[0]=2*ok;

  for(ll i=1;i<n;i++) {
    b[i]=2*(a[i-1]-b[i-1]/2);
  }

  rep(i,n) cout<<b[i]<<" "; cout<<endl;

  return 0;
}
