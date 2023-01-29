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
  ll n; cin>>n;
  vector<ll> a(n); rep(i,n) cin>>a[i];

  map<ll,ll> mp;

  rep(i,n) mp[a[i]]++;

  ll n0=0;
  ll n1=0;

  for(auto x:mp) {
    n0+=(x.second)*(x.second-1)*(x.second-2)/6;
    n1+=(x.second)*(x.second-1)/2*(n-x.second);
  }

  // cout<<n1<<endl;

  cout<<n*(n-1)*(n-2)/6-n0-n1<<endl;

/*
  ll ans=0;

  set<ll> inter;
  map<ll,ll> mp0,mp1;

  for(ll i=2;i<n;i++) mp1[a[i]]++;

  if(mp1[a[0]] > 0) inter.insert(a[0]);

  for(ll i=1;i<n-1;i++) {
    ll n1=i-mp0[a[i]];
    ll n2=n-1-i-(mp1[a[i]]);
    ll n0=inter.size();
*/

/*
    printf("i %lld\n", i);
    cout<<"inter "; for(auto i:inter) cout<<i<<" "; cout<<endl;

    printf("mp0[5] %lld  mp1[5] %lld\n", mp0[5], mp1[5]);

    // mp1[a[i+1]]--;

    if(mp1[a[i+1]]-1 <= 0 && inter.find(a[i+1]) != inter.end()) {
      inter.erase(a[i+1]);
    } // del elem

    if(mp1[a[i]] > 0) {
      inter.insert(a[i]);
    } // add elem

    mp1[a[i+1]]--;
    mp0[a[i]]++;

    ans+=(n1*n2)-n0;

    printf("i %lld  n0 %lld  n1 %lld  n2 %lld\n", i, n0 ,n1, n2);

    printf("i %lld  ans %lld\n", i ,ans);
  }

  cout<<ans<<endl;
*/

/*
  mp[a[0]]++;

  for(ll i=1;i<n;i++) {
    ans+=(i-mp[a[i]]);
    mp[a[i]]++;
  }
*/


/*
  map<ll,ll> mp;
  set<ll> st;
  rep(i,n) st.insert(a[i]);
  rep(i,n) mp[a[i]]++;

  rep(i,n-2) {
    ll n0=st.size()-1;

    mp[a[i]]--;

    if(mp[a[i]] < 1) st.erase(a[i]);

    ans+=n0*(n0-1)/2;

  }
*/



/*
  map<ll,ll> mp;
  rep(i,n) mp[a[i]]++;

  ll ans=1;
  ll cnt=0;
  for(auto i:mp) {
    ans*=(i.second);
    cnt++;
  }

  cout<<ans*nCr<<endl;
*/
  return 0;
}
