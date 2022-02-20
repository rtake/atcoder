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
  vector<int> a,b,c;
  a=b=c=vector<int>(m);
  rep(i,m) cin>>a[i]>>b[i]>>c[i];
  rep(i,m) a[i]--,b[i]--;

  // vector< vector< vector<int> > > V(n,vector< vector<int> >(n));
  vector< vector< set<int> > > V(n,vector< set<int> >(n));
  // rep(i,m) V[a[i]][b[i]][i]=V[b[i]][a[i]][i]=1;
  rep(i,m) {
    // V[a[i]][b[i]].push_back(i);
    // V[b[i]][a[i]].push_back(i);
    V[a[i]][b[i]].insert(i);
    V[b[i]][a[i]].insert(i);
  }

  vector< vector<int> > d(n, vector<int>(n,1e9));
  rep(i,m) d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];
  rep(i,n) d[i][i]=0;

  for(ll i=0;i<n;i++) for(ll j=i+1;j<n;j++) rep(k,n) {
    if(d[i][j] > d[i][k]+d[k][j]) {
      // printf("d[%lld][%lld] > d[%lld][%lld]+d[%lld][%lld]\n",i,j,i,k,k,j);

      d[i][j]=d[j][i]=d[i][k]+d[k][j];

      V[i][j]=set<int>();
      for(auto v:V[i][k]) V[i][j].insert(v);
      for(auto v:V[k][j]) V[i][j].insert(v);
      V[j][i]=V[i][j];
    } else if(d[i][j] == d[i][k]+d[k][j]) {
      for(auto v:V[i][k]) V[i][j].insert(v);
      for(auto v:V[k][j]) V[i][j].insert(v);

      V[j][i]=V[i][j];
    }

/*
    rep(i,n) {
      rep(j,n) {
        if(V[i][j].size() >= 1) for(auto v:V[i][j]) cout<<V[i][j][0];
        else cout<<-1<<" ";
      }

      cout<<endl;
    }

    cout<<endl;
*/
  }

  vector<int> used(m,1);
  
  rep(i,n) rep(j,n) {
    for(auto v:V[i][j]) used[v]=0;
  }

  int ans=0;
  rep(i,m) ans+=used[i];

  cout<<ans<<endl;

  return 0;
}
