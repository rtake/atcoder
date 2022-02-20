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


ll popcount(ll x) {
  ll count=0;

  while(x > 0) {
    count+=(x&1);
    x>>=1LL;
  }

  return count;
}


vector<ll> memo;


ll f(ll x) {
  if(memo[x] >= 0LL) return memo[x];
  return memo[x]=f(x%popcount(x))+1;
}


ll popcount(string x) {
  ll count=0;
  for(auto c:x) count+=(c-'0');
  return count;
}


int main() {
  ll n;
  string x;
  cin>>n>>x;

  memo=vector<ll>(n+1,-1);

  memo[0]=0;

  ll count=popcount(x);
  ll count0=count+1;
  ll count1=count-1;

  ll z0=0,z1=0;
  if(count0 > 0) { rep(i,n) z0+=(x[i]-'0')*binpower(2,n-1-i,count0); }
  if(count1 > 0) { rep(i,n) z1+=(x[i]-'0')*binpower(2,n-1-i,count1); }

  for(ll i=n;i>=0;i--) f(i);

  for(ll i=0;i<n;i++) {
    if(x[i] == '0') {
      if(count0 == 0LL) {
        cout<<0<<endl;
      } else {
        ll _z0=(z0+binpower(2,n-1-i,count0))%count0;
        cout<<memo[_z0%count0]+1<<endl;
      }
    } else {
      if(count1 == 0LL) {
        cout<<0<<endl;
      } else {
        ll _z1=(z1+count1-binpower(2,n-1-i,count1))%count1;
        cout<<memo[_z1%count1]+1<<endl;
      }
    }
  }

  return 0;
}
