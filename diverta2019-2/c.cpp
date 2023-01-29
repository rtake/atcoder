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



int main() {
  ll n; cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];

  sort(ALL(a));

  deque<ll> q0,q1,qz;

  rep(i,n) {
    if(a[i] > 0) q0.push_back(a[i]);
    else q1.push_back(a[i]);

    if(a[i] == 0LL) {
      q0.push_back(0);
      q1.push_back(0);
    }
  }

  if(q1.empty()) {
    // all positive //

    ll m=0;
    vector<ll> x,y;

    x.push_back(q0.front());
    y.push_back(q0.back());

    m=x[0]-y[0];
    
    q0.pop_front();
    q0.pop_back();

    // while(q0.size() > 1) {
    rep(i,(n-1)-2) {
      x.push_back(m);
      y.push_back(q0.back());

      m-=q0.back();

      q0.pop_back();
    }

    x.push_back(q0.front());
    y.push_back(m);

    m=q0.back()-m;

    printf("%lld\n", m);

    rep(i,n-1) printf("%lld %lld\n", x[i], y[i]);

    return 0;
  }


  if(q0.empty()) {
    // all negative //

    ll m=0;
    vector<ll> x,y;

    x.push_back(q1.back());
    y.push_back(q1.front());

    m=x[0]-y[0];
    
    q1.pop_front();
    q1.pop_back();

    rep(i,(n-1)-2) {
      x.push_back(m);
      y.push_back(q1.back());

      m-=q1.back();

      q1.pop_back();
    }

    x.push_back(q1.front());
    y.push_back(m);

    m=m-q1.back();

    printf("%lld\n", m);

    rep(i,n-1) printf("%lld %lld\n", x[i], y[i]);

    return 0;
  }


  ll m=0;
  vector<ll> x,y;

  x.push_back(q1.front());
  y.push_back(q0.back());

  m=x[0]-y[0];

  q1.pop_front();
  q0.pop_back();


  if(q0.empty()) {

    while(!q1.empty()) {
      x.push_back(m);
      y.push_back(q1.front());

      m-=q1.front();

      q1.pop_front();
    }

    printf("%lld\n", m);

    rep(i,n-1) printf("%lld %lld\n", x[i], y[i]);

    return 0;
  } 


  if(q1.empty()) {



    printf("%lld\n", m);

    rep(i,n-1) printf("%lld %lld\n", x[i], y[i]);

    return 0;
  }


  while(q0.size() > 1) {
    x.push_back(q0.front());
    y.push_back(m);

    m-=q0.front();

    q0.pop_front();
  }


  x.push_back(q0.front());
  y.push_back(q1.back());

  ll _m=q0.front()-q1.back();

  q0.pop_front();
  q1.pop_back();

///*
  while(!q1.empty()) {
    x.push_back(_m);
    y.push_back(q1.front());

    _m-=q1.front();

    q1.pop_front();
  }
//*/

  x.push_back(_m);
  y.push_back(m);

  m=_m-m;

  printf("%lld\n", m);

  rep(i,n-1) printf("%lld %lld\n", x[i], y[i]);

  return 0;
}
