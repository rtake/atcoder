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
  int n;
  cin>>n;

  vector<int> v(101,0);

  for(int i=1;i<=n;i++) {
    int a=i;
    for(int j=2;j*j<=a;j++) {
      while(a%j == 0) {
        v[j]++;
        a/=j;
      }
    }

    if(a > 1) v[a]++;
  }

  int ans=0;
  for(int i=1;i<=100;i++) {
    for(int j=i+1;j<=100;j++) {
      for(int k=j+1;k<=100;k++) {
        if(v[i]>=4 && v[j]>=4 && v[k]>=2) {
          ans++;
        } else if(v[i]>=4 && v[j]>=2 && v[k]>=4) {
          ans++;
        } else if(v[i]>=2 && v[j]>=4 && v[k]>=4) {
          ans++;
        }
      }
    }
  }

  for(int i=1;i<=100;i++) {
    for(int j=i+1;j<=100;j++) {
      if( (v[i]>=14 && v[j]>=4) || (v[i]>=4 && v[j]>=14) ) {
        ans++;
      } else if( (v[i]>=24 && v[j]>=2) || (v[i]>=2 && v[j]>=24) ) {
        ans++;
      }
    }
  }

  for(int i=1;i<=100;i++) {
    if(v[i] >= 74) ans++;
  }

  cout<<ans<<endl;
  return 0;
}
