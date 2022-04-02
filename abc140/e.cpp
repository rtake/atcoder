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
  ll n;
  cin>>n;

  vector<ll> a(n),p(n);
  rep(i,n) cin>>p[i],p[i]--;
  rep(i,n) a[p[i]]=i;

  set<ll> st0,st1;

  st0.insert(-a[n-1]);
  st1.insert(a[n-1]);

  ll ans=0;

  for(ll i=n-2;i>=0;i--) {
    auto lt=st0.lower_bound(-a[i]);
    auto rt=st1.lower_bound(a[i]);

    ll num0,num1,num2,num3;

    if(rt == st1.end()) {
      num0=(n-1)-a[i]+1;
      num1=0;
    } else if(next(rt) == st1.end()) {
      num0=(*rt)-a[i];
      num1=(n-1)-(*rt)+1;
    } else {
      num0=(*rt)-a[i];
      num1=*next(rt)-(*rt);
    }

    if(lt == st0.end()) {
      num2=a[i]+1;
      num3=0;
    } else if(next(lt) == st0.end()) {
      num2=a[i]-(-(*lt));
      num3=(-(*lt))+1;
    } else {
      num2=a[i]-(-(*lt));
      num3=(-(*lt))-(-(*next(lt)));
    }

    ans+=(i+1)*(num0*num3+num1*num2);

    // printf("%lld %lld %lld %lld\n", num0, num1, num2, num3);
    // cout<<ans<<endl;

    st0.insert(-a[i]);
    st1.insert(a[i]);
  }

  cout<<ans<<endl;

  return 0;
}
