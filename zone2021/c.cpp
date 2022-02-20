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



int main() {
  ll n;
  cin>>n;
  vector<ll> a(n),b(n),c(n),d(n),e(n);
  rep(i,n) cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];

  vector< vector< vector<ll> > > 
   dp(n+1, vector< vector<ll> >(4, vector<ll>(5,0)));

  for(ll i=1;i<=n;i++) {  
    for(ll j=1;j<=3;j++) {
      auto v=dp[i-1][j-1];

      ll _a=max(a[i-1],v[0]);
      ll _b=max(b[i-1],v[1]);
      ll _c=max(c[i-1],v[2]);
      ll _d=max(d[i-1],v[3]);
      ll _e=max(e[i-1],v[4]);
      
      ll power=1e18;
      rep(k,5) power=min(power,v[k]);

      ll _power=1e18;
      _power=min(_a,min(_b,min(_c,min(_d,_e))));

      if(_power >= power) {
        v[0]=_a;
        v[1]=_b;
        v[2]=_c;
        v[3]=_d;
        v[4]=_e;
      } 
  
      dp[i][j]=v;
    }
  }

/*
  for(ll i=1;i<=n;i++) {
    rep(j,3) {
      rep(k,5) cout<<dp[i][j+1][k]<<" "; cout<<endl;
    }

    cout<<endl;
  }
*/

  ll ans=0;

  for(ll i=1;i<=n;i++) {
    ll test=1e18;
    rep(k,5) test=min(test,dp[i][3][k]);
    ans=max(ans,test);
  }

  cout<<ans<<endl;

  return 0;
}
