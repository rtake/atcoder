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


vector< vector<ll> > a;

ll dfs(vector<ll> v, vector<ll> used) {
  ll val=0;
  ll n=v.size();

  if(n == 0LL) {
    // cout<<"ok"<<endl;
    return 0;
  } else if(n == 2LL) {
    ll _max=max(v[0],v[1]);
    ll _min=min(v[0],v[1]);

    used.push_back(v[0]);
    used.push_back(v[1]);

    // for(auto i:used) cout<<i<<" "; cout<<endl;

    ll m=used.size();

    rep(i,m/2) {
      val^=a[used[i*2]][used[i*2+1]];
    }

    return val;

    // return a[v[0]][v[1]];
    // return a[_min][_max];
  }

/*
  for(ll i=0;i<n;i++) {
    for(ll j=i+1;j<n;j++) {

      vector<ll> v0;
      for(auto itr:v) {
        if(itr != v[i] && itr != v[j]) v0.push_back(itr);
      }
      
      ll _max=max(v[j],v[i]);
      ll _min=min(v[j],v[i]);
      val=max(val,a[_min][_max]^dfs(v0));
    }
  }
*/

///*
  for(ll i=1;i<n;i++) {

    vector<ll> v0;
    for(auto itr:v) {
      if(itr != v[0] && itr != v[i]) v0.push_back(itr);
    }

    auto used0=used;
    used0.push_back(v[0]);
    used0.push_back(v[i]);

    ll _max=max(v[0],v[i]);
    ll _min=min(v[0],v[i]);
    // val=max(val,a[_min][_max]^dfs(v0,used0));

    val=max(val,dfs(v0,used0));
  }
//*/

  return val;
}


int main() {
  ll n;
  cin>>n;

  // a=vector< vector<ll> >(2*n, vector<ll>(2*n,0));
  a=vector< vector<ll> >(2*n, vector<ll>(2*n,1LL<<30));
 
  for(ll i=0;i<2*n-1;i++) {
    for(ll j=i+1;j<2*n;j++) {
      cin>>a[i][j];
    }
  }

  vector<ll> v;
  rep(i,2*n) v.push_back(i);

  
  ll ans=dfs(v,vector<ll>(0));
  cout<<ans<<endl;

  return 0;
}
