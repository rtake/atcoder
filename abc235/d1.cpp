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


ll a;
vector<ll> memo;
vector<bool> checking;

ll f(string s) {
  // cout<<s<<endl;

  ll x=stoll(s);

  if(x == 1LL) return 0;

  if(memo[x] < 1e18) return memo[x];

  if(checking[x]) return 1e18;
  checking[x]=true;

  if(x%a == 0LL) {
    stringstream ss;
    ss<<(x/a);
    memo[x]=min(memo[x],f(ss.str())+1);
  }

  ll len=s.length();
  string s_sub=s;

  for(ll i=0;i<len-1;i++) {
    // if(s_sub[len-1] == '0') continue;
    // s_sub=s_sub[len-1]+s_sub.substr(0,len-1);

    s_sub=s_sub.substr(1,len-1)+s_sub[0];

    if(s_sub[0] == '0') continue;
    memo[x]=min(memo[x],f(s_sub)+i+1);
  }

  // cout<<s<<" "<<memo[x]<<endl;

  // checking[x]=false;

  return memo[x];
}

int main() {
  string s;
  cin>>a>>s;

  ll n=stoll(s);

  ll inf=1e18;
  memo=vector<ll>(1e7,inf);
  checking=vector<bool>(1e7,false);

  memo[1]=0;

  f(s);

  if(memo[n] == 1e18) cout<<-1<<endl;
  else  cout<<memo[n]<<endl;

  // rep(i,n) cout<<i+1<<" "<<memo[i+1]<<endl;

  return 0;
}
