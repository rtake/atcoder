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
  ll n,a;
  cin>>n>>a,a--;
  string k;
  cin>>k;

  ll l=k.length();

  vector<ll> b(n);
  rep(i,n) cin>>b[i],b[i]--;

  vector<ll> c(n,-1); // turn first arrived

  ll start,dist;
  c[a]=1;

  while(true) {
    if(c[b[a]] > 0) {
      dist=c[a]-c[b[a]]+1;
      start=c[b[a]]; // loop start position
      break;
    }

    c[b[a]]=c[a]+1;
    a=b[a];
  }

  // rep(i,n) cout<<c[i]<<" "; cout<<endl;

  ll ans;
  ll _k=0;

  if(l <= 18) {
    _k=stoll(k);

    if(_k <= start) {
      rep(i,n) if(c[i] == _k) ans=b[i]+1;
    } else {
      _k-=start;
      _k%=dist;
      rep(i,n) if(c[i] == _k+start) ans=b[i]+1;
    }

  } else {
    _k=0;
    ll cur=1;

    for(ll i=l-1;i>=0;i--) {
      _k+=cur*(k[i]-'0');
      _k%=dist;
      cur=(cur*10)%dist;
    }

/*
    for(ll i=0;i<l;i++) {
      _k=(_k*10+(k[i]-'0'))%dist;
    }
*/

    // _k=(_k-start+dist)%dist;
    _k=(_k-start+dist)%dist;

    rep(i,n) if(c[i] == _k+start) ans=b[i]+1;
  }

  cout<<ans<<endl;

  return 0;
}
