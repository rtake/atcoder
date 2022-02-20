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
  ll h,w,n,m;
  cin>>h>>w>>n>>m;

  vector< vector<int> > mat(h, vector<int>(w,0));

  ll a,b;
  rep(i,n) {
    cin>>a>>b;
    a--,b--;
    mat[a][b]=1;
  } 

  rep(i,m) {
    cin>>a>>b;
    a--,b--;
    mat[a][b]=-1;
  }

  vector< vector< vector<bool> > > \
   e(h, vector< vector<bool> >(w, vector<bool>(4,false)));

  for(ll i=0;i<h;i++) {
    if(mat[i][0] == 1) e[i][0][0]=true;
    for(ll j=1;j<w;j++) {
      if(mat[i][j] == 1) e[i][j][0]=true;
      else if(mat[i][j] == -1) e[i][j][0]=false;
      else e[i][j][0]=e[i][j-1][0];
    }
  }

  for(ll i=0;i<h;i++) {
    if(mat[i][w-1] == 1) e[i][w-1][1]=true;
    for(ll j=w-2;j>=0;j--) {
      if(mat[i][j] == 1) e[i][j][1]=true;
      else if(mat[i][j] == -1) e[i][j][1]=false;
      else e[i][j][1]=e[i][j+1][1];
    }
  }

  for(ll j=0;j<w;j++) {
    if(mat[0][j] == 1) e[0][j][2]=true;
    for(ll i=1;i<h;i++) {
      if(mat[i][j] == 1) e[i][j][2]=true;
      else if(mat[i][j] == -1) e[i][j][2]=false;
      else e[i][j][2]=e[i-1][j][2];
    }
  }

  for(ll j=0;j<w;j++) {
    if(mat[h-1][j] == 1) e[h-1][j][3]=true;
    for(ll i=h-2;i>=0;i--) {
      if(mat[i][j] == 1) e[i][j][3]=true;
      else if(mat[i][j] == -1) e[i][j][3]=false;
      else e[i][j][3]=e[i+1][j][3];
    }
  }

  int ans=0;
  rep(i,h) rep(j,w) {

    bool akari=false; 
    rep(k,4) akari|=e[i][j][k];

    if(akari) ans++;
  }

  cout<<ans<<endl;

  return 0;
}
