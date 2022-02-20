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


ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}


int main() {
  int n,m;
  cin>>n>>m;

  ll inf=1e18;

  vector< vector<ll> > d(n, vector<ll>(n,inf));
  rep(i,n) d[i][i]=0;

  rep(i,m) {
    ll u,v,l;
    cin>>u>>v>>l;
    u--,v--;

    d[u][v]=d[v][u]=l;
  }

/*
  cout<<endl;
  rep(i,n) { rep(j,n) cout<<d[i][j]<<" "; cout<<endl; }
  cout<<endl;
*/

  rep(k,n) rep(i,n) rep(j,n) {
    if(k == 0 || i == 0 || j == 0) continue;
    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  }

/*
  cout<<endl;
  rep(i,n) { rep(j,n) cout<<d[i][j]<<" "; cout<<endl; }
  cout<<endl;
*/

  ll ans=inf;
  for(int i=1;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      ans=min(ans,d[0][i]+d[i][j]+d[j][0]);
      // printf("i %d j %d ans %lld\n", i, j, ans);
    }
  }

  if(ans >= inf) ans=-1;
  cout<<ans<<endl;

  return 0;
}
