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
  ll x,y,z,k;
  cin>>x>>y>>z>>k;
  vector<ll> a(x+10,0),b(y+10,0),c(z+10,0);
  rep(i,x) cin>>a[i];
  rep(i,y) cin>>b[i];
  rep(i,z) cin>>c[i];

  sort(ALL(a),greater<ll>());
  sort(ALL(b),greater<ll>());
  sort(ALL(c),greater<ll>());

  ll ans=0,cnt=0;
  ll pos_a=0,pos_b=0,pos_c=0;
  priority_queue<ll> pq;

  k=x*y*z;
  while(cnt < k) {
    ll _max=max(a[pos_a],max(b[pos_b],c[pos_c]));

    if(_max == a[pos_a]) {
      for(ll i=pos_b;i<y;i++) for(ll j=pos_c;j<z;j++,cnt++) pq.push(a[pos_a]+b[i]+c[j]);
      pos_a++;
    }else if(_max == b[pos_b]) {
      for(ll i=pos_a;i<x;i++) for(ll j=pos_c;j<z;j++,cnt++) pq.push(a[i]+b[pos_b]+c[j]);
      pos_b++;
    } else if(_max == c[pos_c]) {
      for(ll i=pos_a;i<x;i++) for(ll j=pos_b;j<y;j++,cnt++) pq.push(a[i]+b[j]+c[pos_c]);
      pos_c++;
    }
  }

  cout<<"size "<<pq.size()<<endl;

  rep(i,k) {
    cout<<pq.top()<<endl;
    pq.pop();
  }

  return 0;
}
