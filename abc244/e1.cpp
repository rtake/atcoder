# include <bits/stdc++.h>
# include <atcoder/all>

typedef long long ll;

using namespace std;
using namespace atcoder;

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



int main() {
  ll n,m,k,s,t,x; cin>>n>>m>>k>>s>>t>>x;
  s--;
  t--;
  x--;

  mod=998244353;
  
  // vector< vector<ll> > G(n);
  vector<ll> u(m),v(m);

  rep(i,m) {
    cin>>u[i]>>v[i];
    u[i]--,v[i]--;
  }

  vector< vector< vector<ll> > > \
   dp(k+1, vector< vector<ll> > (n, vector<ll>(2,0)));


  dp[0][s][0]=1;

  rep(i,k) {

    rep(j,m) {

      if(u[j] == x) {

        rep(l,2) {
          (dp[i+1][v[j]][l]+=dp[i][u[j]][l])%=mod;
          (dp[i+1][u[j]][(l+1)%2]+=dp[i][v[j]][l])%=mod;
        }

      } else if(v[j] == x) {

        rep(l,2) {
          (dp[i+1][v[j]][(l+1)%2]+=dp[i][u[j]][l])%=mod;
          (dp[i+1][u[j]][l]+=dp[i][v[j]][l])%=mod;
        }

      } else {

        rep(l,2) {
          (dp[i+1][v[j]][l]+=dp[i][u[j]][l])%=mod;
          (dp[i+1][u[j]][l]+=dp[i][v[j]][l])%=mod;
        }
      
      }

    }

  }

/*
  rep(i,k+1) {
    // rep(j,n) cout<<dp[i][j][0]+dp[i][j][1]<<" ";

    rep(j,n) cout<<dp[i][j][0]<<","<<dp[i][j][1]<<"\t";

    cout<<endl;
  }
*/

  cout<<dp[k][t][0]<<endl;

  return 0;
}
