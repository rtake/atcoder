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
  ll n,k;
  cin>>n>>k;
  vector<ll> x(n),y(n);
  vector<char> c(n);
  rep(i,n) cin>>x[i]>>y[i]>>c[i];

  vector<ll> v(k*k);
  vector< vector<ll> > B(k, vector<ll>(k,0)),W(k, vector<ll>(k,0));

  rep(i,n) {
    ll xx=x[i]%k;
    ll yy=y[i]%k;


    if(c[i] == 'B') {
      B[xx][yy]++;
    } else {
      W[xx][yy]++;
    }
  }

  vector<ll> xBcum(k*2),yBcum(k*2);
  vector<ll> xWcum(k*2),yWcum(k*2);

  rep(i,k) rep(j,k) {
    xBcum[i]+=B[i][j];
    yBcum[j]+=B[i][j];

    xWcum[i]+=W[i][j];
    yWcum[j]+=W[i][j];
  }


  /*
  for(auto i:V) {
    for(auto j:i) cout<<j<<" ";
    cout<<endl;
  }
  */


  //*
/*// rep(i,k) {
  for(ll i=k-1;i>=0;i--) {

    rep(j,k) {
      cout<<V[j][i]<<" ";
    }

    cout<<endl;
  }
*/  //*/


  // for(auto i:xWcum) cout<<i<<" "; cout<<endl;
  for(auto i:yWcum) cout<<i<<" "; cout<<endl;


  ll sum=0;
  rep(i,k) sum+=xBcum[i];

  // rep(i,k) rep(j,k) sum+=v[i*k+j];


  ll ans=sum;

  cout<<sum<<endl;

///*
  // rep(i,k*2) {
  for(ll i=1;i<=2*k;i++) {
  // for(ll i=1;i<k;i++) {

    sum-=xBcum[(i-1)%(k*2)];
    sum+=xBcum[(i+k-1)%(k*2)];

    sum+=xWcum[(i-1)%(k*2)];
    sum-=xWcum[(i+k-1)%(k*2)];


    ans=max(ans,abs(sum));

    ll sum0=sum;

    printf("i %lld sum0 %lld\n",i,sum0);

///*
    for(ll j=1;j<=2*k;j++) {
    // for(ll j=1;j<k;j++) {
      // sum0-=yBcum[(j-1)%(k*2)];
      // sum0+=yBcum[(j+k-1)%(k*2)];

      sum0+=yWcum[(j-1)%(k*2)];
      sum0-=yWcum[(j+k-1)%(k*2)];

      ans=max(ans,abs(sum0));

      printf("i %lld j %lld sum0 %lld\n",i,j,sum0);
    }
//*/


  } // bottom-left of black 
//*/

  cout<<abs(ans)<<endl;

  return 0;
}
