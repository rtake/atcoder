# include <bits/stdc++.h>
# include <atcoder/all>

typedef long long ll;

using namespace std;
using namespace atcoder;

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

ll _add(ll a, ll b) { return a+b; }
ll _xor(ll a, ll b) { return a^b; }

ll e() { return 0; }

int main() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];

  segtree<ll,_add,e> seg(a);
  segtree<ll,_xor,e> _seg(a);

  ll l,r;
  ll ans=0;

  l=0,r=1;
  while(l < n && r < n) {

    while(r < n) {

      if(seg.prod(l,r+1) == _seg.prod(l,r+1)) {

        ll cnt=2;
        while(r+1 < n) {
          if(seg.prod(l,r+2) == _seg.prod(l,r+2)) {
            cnt++;
            r++;
          } else break;
        }

        cout<<l<<" "<<r<<endl;
        cout<<ans<<endl;

        ans+=cnt*(cnt-1)/2;
        break;
      }

      r++;
    }

    r++;
    l++;
  }

  ans+=n;

  cout<<ans<<endl;
  return 0;
}
