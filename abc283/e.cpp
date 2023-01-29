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

//////////////////////////////////////////////////////////////////////
/*

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

*/
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// https://atcoder.jp/contests/abc234/editorial/3223 
///*

vector<ll> fac,finv,inv;

void binom_init() {
  const ll MAX=5010;

  fac.resize(MAX);
  finv.resize(MAX);
  inv.resize(MAX);
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<MAX; i++){
      fac[i] = fac[i-1]*i%mod;
      inv[i] = mod-mod/i*inv[mod%i]%mod;
      finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%mod*finv[n-r]%mod;
}

//*/
//////////////////////////////////////////////////////////////////////



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

ll h,w;
vector< vector<ll> > a;
bool f(ll x, ll y) {
/*
  if(a[x][y] != a[x-1][y] && a[x][y] != a[x+1][y] && a[x][y] != a[x][y-1] && a[x][y] != a[x][y+1]) {
    return false;
  }
*/

  map<ll,ll> mp;
  mp[a[x-1][y]]++;
  mp[a[x+1][y]]++;
  mp[a[x][y-1]]++;
  mp[a[x][y+1]]++;

  if(mp[a[x][y]] == 0) return false;
  return true;
}

int main() {
  cin>>h>>w;
  a=vector< vector<ll> > (h+2, vector<ll>(w+2, -1));
  rep(i,h) {
    rep(j,w){
      cin>>a[i+1][j+1];
    }
  }

  for(ll j=0;j<=w+1;j++) {
    a[0][j]=j+2;
  }

  vector< vector<ll> > dp(h+2, vector<ll>(2,1e9));
  dp[0][0]=0;
  dp[1][0]=0;
  // dp[0][1]=0;
  // dp[1][1]=0;

/*
  for(ll j=1;j<=w;j++) {
    bool ok=true;
    if(!f(1,j)) ok=false;
    if(ok) dp[1]=0;
  }
*/

  for(ll i=1;i<=h-1;i++) {
    bool ok=true;
    vector<ll> a0=a[i];
    vector<ll> a1=a[i+1];

    // step. 1 : no action
    ok=true;
    for(ll j=1;j<=w;j++) {
      if(!f(i+1,j)) ok=false;
    }
    if(ok) dp[i+1][0]=min(dp[i+1][0], min(dp[i][0], dp[i][1]));
    else cout<<i<<" step 1 false!"<<endl;

    // step. 2 : i
    for(ll j=1;j<=w;j++) a[i][j]=1-a[i][j];
    ok=true;
    for(ll j=1;j<=w;j++) {
      if(!f(i+1,j)) ok=false;
    }
    if(ok) dp[i+1][0]=min(dp[i+1][0], dp[i][1]);
    else cout<<i<<" step 2 false!"<<endl;

    // step. 3 i+1
    a[i]=a0;
    for(ll j=1;j<=w;j++) a[i+1][j]=1-a[i+1][j];
    ok=true;
    for(ll j=1;j<=w;j++) {
      if(!f(i+1,j)) ok=false;
    }
    if(ok) dp[i+1][1]=min(dp[i+1][1], min(dp[i][0], dp[i][1])+1);
    else cout<<i<<" step 3 false!"<<endl;

    a[i]=a0;
    a[i+1]=a1;
  }

  for(ll i=2;i<=h+1;i++) {
    cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
  }

  if(min(dp[h][0], dp[h][1]) < 1e9) cout<<min(dp[h][0],dp[h][1])<<endl;
  else cout<<-1<<endl;

  return 0;
}
