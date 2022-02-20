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
  int t;
  cin>>t;
  ll r,g,b;
  vector<ll> ans(t,1e18);
  rep(i,t) {
    cin>>r>>g>>b;

    if(r == g) { ans[i]=r; }
    if(g == b) { ans[i]=g; }
    if(b == r) { ans[i]=b; }

    ll rgb=r+g+b, _ans;

    _ans=0;
    if(abs(r-g)%3 == 0 && b >= abs(r-g)/3-1) {
      _ans+=abs(r-g)/3-1, b-=abs(r-g)/3-1;
      if(b == 0) { _ans++, b=2;}
      _ans++, b--;
      _ans+=(rgb-b)/2;
      ans[i]=min(ans[i],_ans);
    }

    _ans=0;
    if(abs(g-b)%3 == 0 && r >= abs(g-b)/3-1) {
      _ans+=abs(g-b)/3-1, r-=abs(g-b)/3-1;
      if(r == 0) { _ans++, r=2;}
      _ans++, r--;
      _ans+=(rgb-r)/2;
      ans[i]=min(ans[i],_ans);
    }

    _ans=0;
    if(abs(b-r)%3 == 0 && g >= abs(b-r)/3-1) {
      _ans+=abs(b-r)/3-1, g-=abs(b-r)/3-1;
      if(g == 0) { _ans++, g=2;}
      _ans++, g--;
      _ans+=(rgb-g)/2;
      ans[i]=min(ans[i],_ans);
    }

    if(ans[i] == 1e18) ans[i]=-1;
  }

  rep(i,t) cout<<ans[i]<<endl;

  return 0;
}
