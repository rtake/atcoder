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


ll op(ll a, ll b) { return a+b; }
ll e() { return 0; }

int main() {
  ll n; cin>>n;
  vector<ll> c(n); rep(i,n) cin>>c[i],c[i]--;
  vector<ll> x(n); rep(i,n) cin>>x[i],x[i]--;

  vector< vector<ll> > C(n);
  rep(i,n) C[c[i]].push_back(x[i]);

  segtree<ll,op,e> seg(vector<ll>(n,0));


  ll ans=0;

  // Sum up all elem
  rep(i,n) {
    ll n_greater=seg.prod(x[i]+1,n);
    ans+=n_greater;

    ll cnt=seg.get(x[i]);
    seg.set(x[i],max(cnt+1,0LL));
  }

  rep(i,n) {
    ll cnt=seg.get(x[i]);
    seg.set(x[i],max(cnt-1,0LL));
  }

  // Substrate for i-th color
  rep(i,n) {

    // for balls with color i, ...
    for(auto j:C[i]) {
      ll n_greater=seg.prod(j+1,n);
      ans-=n_greater;

      ll cnt=seg.get(j);
      seg.set(j,max(cnt+1,0LL));
    }

    for(auto j:C[i]) {
      ll cnt=seg.get(j);
      seg.set(j,max(cnt-1,0LL));
    }
  }

  cout<<ans<<endl;

  return 0;
}