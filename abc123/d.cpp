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

  while(cnt < k) {
    pq.push(a[pos_a]+b[pos_b]+c[pos_c]);
    cnt++;

    for(ll _x=pos_a+1;_x<x;_x++,cnt++) pq.push(a[_x]+b[pos_b]+c[pos_c]);
    for(ll _y=pos_b+1;_y<y;_y++,cnt++) pq.push(a[pos_a]+b[_y]+c[pos_c]);
    for(ll _z=pos_c+1;_z<z;_z++,cnt++) pq.push(a[pos_a]+b[pos_b]+c[_z]);

    for(ll _x=pos_a+1;_x<x;_x++) {
      for(ll _y=pos_b+1;_y<y;_y++) {
        pq.push(a[_x]+b[_y]+c[pos_c]);
        cnt++;
      }
    }

    for(ll _z=pos_c+1;_z<z;_z++) {
      for(ll _y=pos_b+1;_y<y;_y++) {
        pq.push(a[pos_a]+b[_y]+c[_z]);
        cnt++;
      }
    }

    for(ll _x=pos_a+1;_x<x;_x++) {
      for(ll _z=pos_c+1;_z<z;_z++) {
        pq.push(a[_x]+b[pos_b]+c[_z]);
        cnt++;
      }
    }

    pos_a++,pos_b++,pos_c++;
  }

  rep(i,k) {
    cout<<pq.top()<<endl;
    pq.pop();
  }

  return 0;
}
