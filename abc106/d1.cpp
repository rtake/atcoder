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
  ll n,m,_q;
  cin>>n>>m>>_q;
  vector<ll> l(m),r(m),p(_q),q(_q);
  rep(i,m) cin>>l[i]>>r[i];

  rep(i,_q) cin>>p[i]>>q[i];

  vector< vector<ll> > mat(n+10, vector<ll>(n+10,0));

  rep(i,m) {
    mat[l[i]][r[i]]++;
    // mat[l[i]+1][r[i]+1]--;
  }

  for(ll i=1;i<n+10;i++) { // for left
    for(ll j=1;j<n+10;j++) { // for right
      mat[i][j]+=mat[i][j-1];
    } // for right
  } // for left

  for(ll i=1;i<n+10;i++) { // for left
    for(ll j=1;j<n+10;j++) { // for right
      mat[i][j]+=mat[i-1][j];
    } // for right
  } // for left
  

/*
  rep(i,n+2) {
    rep(j,n+2) cout<<mat[i][j]<<" ";
    cout<<endl;
  }
*/

  rep(i,_q) {
    cout<<mat[n+1][q[i]]-mat[p[i]-1][q[i]]<<endl;
  }

  return 0;
}
