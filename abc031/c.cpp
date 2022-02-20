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
  vector<int> a(n+1);
  rep(i,n) cin>>a[i+1];

  vector<int> cum0(n+1,0),cum1(n+1,0);

  for(int i=1;i<=n;i++) {
    cum0[i]=cum0[i-1];
    cum1[i]=cum1[i-1];

    if(i%2 == 0) cum0[i]+=a[i];
    else cum1[i]+=a[i];
  }


  int ans=-1e9;

  for(int tak=1;tak<=n;tak++) {

    int aok;
    int r=aok, l=1;
    int ltest,rtest,test;

    ltest=rtest=test=-1e9;


    aok=1;
    while(aok < tak) {

      if(aok%2 == 0) {
        if(cum1[tak]-cum1[aok] > ltest) {
          ltest=cum1[tak]-cum1[aok];
          l=aok;
          test=cum0[tak]-cum0[aok-1];
        }
      } else {
        if(cum0[tak]-cum0[aok] > ltest) {
          ltest=cum0[tak]-cum0[aok];
          l=aok;
          test=cum1[tak]-cum1[aok-1];
        }
      }

      aok++;
    }


    aok=tak+1;
    while(aok <= n) {

      if(tak%2 == 0) {
        if(cum1[aok]-cum1[tak-1] > max(ltest,rtest)) {
          rtest=cum1[aok]-cum1[tak-1];
          r=aok;
          test=cum0[aok]-cum0[tak-1];
        }
      } else if(tak%2 == 1) {
        if(cum0[aok]-cum0[tak-1] > max(ltest,rtest)) {
          rtest=cum0[aok]-cum0[tak-1];
          r=aok;
          test=cum1[aok]-cum1[tak-1];
        }
      }

      aok+=2;
    }

    ans=max(test,ans);

/*
    if(ltest >= rtest) {
      // printf("tak %d ltest %d rtest %d\n", tak, ltest, rtest);
      if(l%2 == 0) ans=max(ans,cum0[tak]-cum0[l-1]);
      else ans=max(ans,cum1[tak]-cum1[l-1]);
    } else {
      if(tak%2 == 0) ans=max(ans,cum0[r]-cum0[tak-1]);
      else ans=max(ans,cum1[r]-cum1[tak-1]);
    }
*/

    // printf("tak %d l %d r %d\n", tak, l, r);
    // printf("ans %d test %d ltest %d rtest %d\n", ans, test, ltest, rtest);
    // cout<<endl;
  }

  // for(auto x:cum0) cout<<x<<" "; cout<<endl;
  // for(auto x:cum1) cout<<x<<" "; cout<<endl;

  cout<<ans<<endl;

  return 0;
}
