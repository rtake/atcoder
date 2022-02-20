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
  ll n,a;
  cin>>n>>a;
  vector<ll> x(n);
  rep(i,n) cin>>x[i];

  ll n0=n/2;
  ll n1=n-n0;
  map< pair<ll,ll>,ll > mp0,mp1;

///*
  for(ll bit=0;bit<(1<<n0);bit++) {
    ll num=0,sum=0;

    rep(i,n0) {
      if((bit>>i)&1 > 0) num++,sum+=x[i];
    }

    mp0[make_pair(num,sum)]++;
  }
//*/

  // for(auto x:mp0) cout<<x.first.first<<":"<<x.first.second<<"="<<x.second<<" ";
  // cout<<endl;


///*
  for(ll bit=0;bit<(1<<n1);bit++) {
    ll num=0,sum=0;

    for(ll i=0;i<n1;i++) {
      if((bit>>i)&1 > 0) num++,sum+=x[i+n0];
    }

    mp1[make_pair(num,sum)]++;
  }
//*/

  ll ans=0;

  for(auto x:mp0) {
    auto p=x.first;
    ll num=p.first, sum=p.second, cnt=x.second;
    
    if(num == 0 || sum == 0) continue;
    if(a*num == sum) ans+=cnt;
  }

  // cout<<ans<<endl;

  for(auto x:mp1) {
    auto p=x.first;
    ll num=p.first, sum=p.second, cnt=x.second;
    
    if(num == 0 || sum == 0) continue;
    // if(a*num == sum) ans+=cnt*(cnt+1)/2;
    if(a*num == sum) ans+=cnt;
  } 

  // cout<<ans<<endl;

///*
  for(ll i=1;i<=n0;i++) {
    for(ll j=1;j<=n0*50;j++) {
      for(ll k=1;k<=n1;k++) {
        auto p0=make_pair(i,j);
        auto p1=make_pair(k,a*(i+k)-j);
        ans+=mp0[p0]*mp1[p1];
      }
    }
  }
//*/

  cout<<ans<<endl;

  // for(auto x:mp0) cout<<x.first.first<<" "<<x.first.second<<" ";
  // cout<<endl;

  return 0;
}
