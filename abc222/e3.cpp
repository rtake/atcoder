# include <bits/stdc++.h>
# include <atcoder/all>

typedef long long ll;

using namespace std;
using namespace atcoder;

// using mint=modint1000000007;
using mint=modint998244353;

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


bool found;
vector<ll> C;
vector< vector< pair<ll,ll> > > G;


// void dfs(ll cur, ll par=-1) {
bool dfs(ll cur, ll par, ll goal) {

  if(cur == goal) {
    // found=true;
    return true;
  }

  for(auto edge:G[cur]) {
    if(edge.first == par) continue;

    bool res=dfs(edge.first,cur,goal);

    if(res) {
      C[edge.second]++;
      return true;
    }
  }

  return false;
}


int main() {
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll> a(m);
  rep(i,m) cin>>a[i],a[i]--;

  mod=998244353;

  C=vector<ll>(n);
  G=vector< vector< pair<ll,ll> > >(n);

  ll u,v;
  rep(i,n-1) {
    cin>>u>>v;
    u--,v--;
    G[u].push_back({v,i});
    G[v].push_back({u,i});
  }

  rep(i,m-1) dfs(a[i],-1,a[i+1]);

///*

  ll num=0;
  rep(i,n-1) num+=C[i];

  vector<ll> dp(num+10,0);

  dp[0]=1;

  rep(i,n-1) {

    for(ll j=num;j>=0;j--) {
      if(j-C[i] < 0) continue;

      dp[j]+=dp[j-C[i]];
      dp[j]%=mod;
    }

    // rep(i,num+1) cout<<dp[i]<<" "; cout<<endl;
  }

  ll ans=0;
  for(ll r=0;r<=num;r++) {
    ll b=num-r;

    if(r-b == k) ans=(ans+dp[r])%mod;
  }

  cout<<ans<<endl;
//*/

  return 0;
}
