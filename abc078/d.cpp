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

ll n,z,w;
vector<ll> a;
vector< vector<ll> > memo;


ll f(ll top, ll turn) {
  if(memo[top][turn] != -1) return memo[top][turn];
  if(top == n-1) return a[top];

  ll score;
  if(turn == 0) {
    // X
    score=0;
    for(ll j=top;j<n;j++) {
      for(ll k=j+1;k<n;k++) {
        score=max(score,abs(a[j]-f(k,1)));
      }
    }
  } else if(turn == 1) {
    // Y
    score=1e18;
    for(ll j=top;j<n;j++) {
      for(ll k=j+1;k<n;k++) {
        score=min(score,abs(a[j]-f(k,0)));
      }
    }
  }

  // printf("top %lld turn %lld score %lld\n", top, turn, score);
  return memo[top][turn]=score;
}


int main() {
  cin>>n>>z>>w;
  a=vector<ll>(n);
  rep(i,n) cin>>a[i];

  memo=vector< vector<ll> >(n, vector<ll>(n,-1));

  f(0,0);

  ll ans=abs(a[n-1]-w);
  ans=max(ans,f(0,0));
  // cout<<ans<<endl;

  rep(i,n) cout<<memo[i][0]<<" "<<memo[i][1]<<endl;

  return 0;
}
