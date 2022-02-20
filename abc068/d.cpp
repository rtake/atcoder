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
  ll k;  
  cin>>k;

  int n;
  vector<ll> a;

  for(n=2;n<=50;n++) {
    a=vector<ll>(n,0);

    ll _k,_b;

    _k=k;

/*
    _b=_k;
    while(_b > 0) {
      if((n-k-1)+(n+1)*_b <= 1e18+1000) break;
      _b/=2;
    }

    a[0]=(n-k-1)+(n+1)*_b;
    _k-=_b;
*/

    // for(ll i=1;i<n;i++) {
    for(ll i=0;i<n-1;i++) {

      _b=_k;
      while(_b > 0) {
        if((n-k-1)+(n+1)*_b <= 1e16+1000) {
          if((n-k-1)+(n+1)*(_b/2) < 0) { 
            break;
          }
        }

        _b/=2;
      }

      a[i]=(n-k-1)+(n+1)*_b;
      _k-=_b;
    }

    // if(_k != 0) continue;

    a[n-1]=(n-k-1)+(n+1)*(_k);

    // rep(i,n) cout<<a[i]<<" "; cout<<endl;


    bool ok=true;
    rep(i,a.size()) {
      if(0 <= a[i] && a[i] <= 1e16+1000) continue;
      ok=false;
    }

    if(ok) break;
  }

  cout<<a.size()<<endl;
  rep(i,a.size()) cout<<a[i]<<" "; cout<<endl;
  
  return 0;
}
