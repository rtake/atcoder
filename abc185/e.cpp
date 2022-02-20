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



int main() {
  ll n,m;
  cin>>n>>m;
  vector<ll> a(n),b(m);
  rep(i,n) cin>>a[i];
  rep(i,m) cin>>b[i];

  vector< pair<ll,ll> > v;
  vector< vector<bool> > check(2);
  check[0]=vector<bool>(n,false);
  check[1]=vector<bool>(m,false);

  ll k=0;
  for(ll i=0;i<n;i++) {
    if(check[0][i]) continue;

    for(ll j=0;j<m;j++) {
      if(check[1][j]) continue;

      if(a[i] == b[j]) {
        check[0][i]=true;
        check[1][j]=true;

        v.emplace_back(i,j);
        k++;
        break;
      }
    }
  }

  sort(ALL(v));

  vector< vector<ll> > dp(k+1, vector<ll>(k+1,1e18));

  dp[0][0]=-1;

  for(ll i=1;i<=k;i++) {
    for(ll j=k;j>0;j--) {

      if(dp[i-1][j-1] == 1e18) continue;

      if(dp[i-1][j-1] < v[i-1].second) {
        dp[i][j]=v[i-1].second;
      } else if(dp[i-1][j-1] > v[i-1].second) {
        dp[i][j-1]=v[i-1].second;
      }
    }
  }

///*
  rep(i,k+1) {
    rep(j,k+1) cout<<dp[i][j]<<" "; cout<<endl;
  }
//*/

  ll cnt=0;
  for(ll j=1;j<=k;j++) {
    if(dp[k][j] < 1e18) cnt=j;
  }

  cout<<(max(m,n)-min(m,n))+(min(m,n)-cnt)<<endl;

  return 0;
}
