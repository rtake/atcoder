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
  if(k == 0) return 1;
  if(k > n) return 0;

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


ll n,k;
vector<ll> p;
vector< vector<ll> > G;


ll dfs(ll cur, ll par) {
  ll val=1,cnt=0;

  for(auto v:G[cur]) {
    if(v == par) continue;

    val=val*dfs(v,cur)%mod;
    cnt++;
  }

  // if(cnt == 0LL) return 1;

  val=val*nCr_mod(k-2,cnt)%mod;
  val=val*p[cnt]%mod;

  // printf("cur %lld val %lld cnt %lld\n", cur, val, cnt);

  return val;
}


int main() {
  mod=1e9+7;

  cin>>n>>k;
  vector<ll> a(n-1),b(n-1);
  rep(i,n-1) cin>>a[i]>>b[i];

  G=vector< vector<ll> >(n);
  rep(i,n-1) {
    a[i]--,b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);

    // G[min(a[i],b[i])].push_back(max(a[i],b[i]));
  }


  // Premutation
  p=vector<ll>(1e5+10);
 
  p[0]=1,p[1]=1;
  for(ll i=2;i<=1e5;i++) p[i]=(p[i-1]*i)%mod;


  nCr_mod_init();


  ll n0=G[0].size();
  ll ans=0;

  ans=(k*nCr_mod(k-1,n0)%mod)*p[n0]%mod;

  for(auto v:G[0]) {
    ans=(ans*dfs(v,0))%mod;
  }

  cout<<ans<<endl;

  return 0;
}
