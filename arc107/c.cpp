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

ll P_mod(ll n, ll k) { return (k==1) ? n%mod : n*((P(n-1,k-1)+mod)%mod)%mod; }

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


struct UnionFind {
  vector<ll> data; // store root | (-size)
 
  UnionFind(ll sz) { data.assign(sz, -1); }
 
  bool unite(ll x, ll y) {
    x=find(x);
    y=find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x,y);
    data[x] += data[y]; // size
    data[y] = x; // root
    return true;
  }
 
  int find(int k) {
    if(data[k] < 0) return k;
    return data[k]=find(data[k]);
  }
 
  int size(int k) { return (-data[find(k)]); }
};


int main() {
  int n,k; cin>>n>>k;
  vector< vector<int> > a(n, vector<int>(n,0));

  mod=998244353;

  rep(i,n) {
    rep(j,n) cin>>a[i][j];
  }

  UnionFind uf0(n),uf1(n);

  rep(r0,n) {
    rep(r1,n) {

      bool ok=true;

      rep(c,n) {
        if(a[r0][c]+a[r1][c] > k) ok=false;
      }

      if(ok) uf0.unite(r0,r1);

    }
  }


  rep(c0,n) {
    rep(c1,n) {

      bool ok=true;

      rep(r,n) {
        if(a[r][c0]+a[r][c1] > k) ok=false;
      }

      if(ok) uf1.unite(c0,c1);

    }
  }


  ll ans=1;

  vector<ll> p(n*n*2+10);

  p[1]=1;

  for(ll x=2;x<=n*n*2;x++) {
    p[x]=(p[x-1]*x)%mod;
  }
  

  rep(i,n) {

    if(uf0.find(i) == i) {
       ll n0=uf0.size(i);

       // ans*=(P_mod(n0,n0)+mod)%mod;
       // ans=(ans+mod)%mod;

      ans=(ans*p[n0])%mod;
    }

    if(uf1.find(i) == i) {
      ll n0=uf1.size(i);
      // ans*=(P_mod(n0,n0)+mod)%mod;
      // ans=(ans+mod)%mod;
      ans=(ans*p[n0])%mod;
    }

  }

  cout<<(ans+mod)%mod<<endl;

/*
  rep(i,50) {
    rep(j,50) {
      if(j <= i) printf("%lld %lld %lld\n", i+1, j+1, (P_mod(i+1,j+1)+mod)%mod);
    }
  }
*/

  return 0;
}
