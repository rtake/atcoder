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


string s;
ll len;
vector<ll> a;

bool isok(ll x) {
  vector<ll> b(len+1,0),c(len+1,0);
  ll cur=0;

  for(ll i=0;i+(x-1)<len;i++) {
    cur+=b[i];

    if((a[i]+cur)%2 == 1LL) continue;
    // if(c[i]%2 == 1LL) continue;

    b[i]++;
    b[i+(x-1)+1]--;
    cur++;
  }

  c[0]+=b[0];
  for(ll i=1;i<len;i++) {
    c[i]=c[i-1]+b[i];
  }

  cout<<"a ";
  rep(i,len+1) cout<<a[i]; cout<<endl;
  cout<<"b ";
  rep(i,len+1) cout<<b[i]; cout<<endl;
  cout<<"c ";
  rep(i,len+1) cout<<c[i]; cout<<endl;

  rep(i,len) {
    if((a[i]+c[i])%2 == 0LL) return false;
  }

  return true;
}


int main() {
  cin>>s;

  len=s.length();
  a=vector<ll>(len+1,0);

  ll cnt=0;
  rep(i,len) {
    a[i]+=(s[i]-'0');
    cnt+=a[i];
  }

  ll ok=0,ng=len+1;
  while(abs(ok-ng) > 1) {
    ll mid=(ok+ng)/2;
    if(isok(mid)) ok=mid;
    else ng=mid;

    cout<<mid<<endl;
  }

  cout<<ok<<endl;

  return 0;
}
