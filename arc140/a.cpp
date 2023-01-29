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
  int n,k; cin>>n>>k;
  string s; cin>>s;

/*
  if(n%2 == 1) {
    ll ans;

    vector<int> a(26,0);
    for(auto c:s) a[c-'a']++;

    sort(ALL(a));

    if(k >= n-a[25]) ans=1;
    else ans=n;

    cout<<ans<<endl;

  } else {

    int ans=n;
    int _n=n/2;

    while(_n > 0) {

      string ss=s.substr(0,_n);
      string tt=s.substr(_n,_n);

      int cnt=0;

      rep(i,_n) {
        if(ss[i] != tt[i]) cnt++;
      }

      cnt=cnt*(n/_n/2);

      if(k >= cnt) {
        k-=cnt;
        ans=_n;
      } else break;

      s=ss;
      _n/=2;
    }

    cout<<ans<<endl;
  }
*/


  int _n=n;
  int ans=n;

  while(_n > 0) {

    // cout<<_n<<" "<<k<<endl;

    if(_n%2 == 1) {

      vector<int> a(26,0);
      for(auto c:s) a[c-'a']++;

      sort(ALL(a));

      int cnt=_n-a[25];

      if(k >= cnt*(n/_n)) ans=1;
      else ans=_n;

      break;

    } else {

      string ss=s.substr(0,_n/2);
      string tt=s.substr(_n/2,_n/2);

      int cnt=0;

      rep(i,_n/2) {
        if(ss[i] != tt[i]) cnt++;
      }

      cnt=cnt*(n/_n);

      if(k >= cnt) {
        k-=cnt;
        ans=_n/2;
      } else break;

      s=ss;
      _n/=2;
    }

  }

  cout<<ans<<endl;

  return 0;
}
