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
  ll n,c;
  cin>>n>>c;
  vector<ll> x(n+1),v(n+1);
  rep(i,n) cin>>x[i+1]>>v[i+1];

  vector<ll> vcum(n+1,0);
  for(ll i=1;i<=n;i++) vcum[i]=vcum[i-1]+v[i];

  ll ans=0;
  vector<ll> vx,_vx,vxmax,_vxmax;

  vx=vxmax=_vx=_vxmax=vector<ll>(n+2,0);
  for(ll i=1;i<=n;i++) {
    vx[i]=vcum[i]-x[i];
    vxmax[i]=max(vxmax[i-1],vx[i]);
  }

  for(ll i=n;i>=1;i--) {
    _vx[i]=(vcum[n]-vcum[i-1])-2*(c-x[i]);
    _vxmax[i]=max(_vxmax[i+1],_vx[i]);
  }

  for(ll i=0;i<=n;i++) ans=max(ans,vxmax[i]+_vxmax[i+1]);


  vx=vxmax=_vx=_vxmax=vector<ll>(n+2,0);
  for(ll i=1;i<=n;i++) {
    vx[i]=vcum[i]-2*x[i];
    vxmax[i]=max(vxmax[i-1],vx[i]);
  }

  for(ll i=n;i>=1;i--) {
    _vx[i]=(vcum[n]-vcum[i-1])-(c-x[i]);
    _vxmax[i]=max(_vxmax[i+1],_vx[i]);
  }

  for(ll i=0;i<=n;i++) ans=max(ans,vxmax[i]+_vxmax[i+1]);

  cout<<ans<<endl;

  return 0;
}
