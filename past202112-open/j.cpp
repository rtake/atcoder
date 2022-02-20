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


vector< vector<int> > dot(vector< vector<int> > M0, vector< vector<int> > M1) {
  auto M=M0;
  M[0][0]=M0[0][0]*M1[0][0]+M0[0][1]*M1[1][0];
  M[0][1]=M0[0][0]*M1[0][1]+M0[0][1]*M1[1][1];
  M[1][0]=M0[1][0]*M1[0][0]+M0[1][1]*M1[1][0];
  M[1][1]=M0[1][0]*M1[0][1]+M0[1][1]*M1[1][1];
  return M;
}


vector< vector<int> > inv(vector< vector<int> > M) {
  auto M0=M;
  int det=M[0][0]*M[1][1]-M[0][1]*M[1][0];
  M0[0][0]=M[1][1]/det;
  M0[0][1]=-M[0][1]/det;
  M0[1][0]=-M[1][0]/det;
  M0[1][1]=M[0][0]/det;
  return M0;
}


int main() {
  int n,q;
  cin>>n>>q;

  vector< vector<int> > M(2, vector<int>(2));
  M[0][0]=1; M[0][1]=0;
  M[1][0]=0; M[1][1]=1;

  auto M0=M;
  auto _M=M;

  vector< vector<int> > G(2*n, vector<int>(2*n,0));

  int z;
  rep(i,q) {
    cin>>z;

    if(z == 1) {
      int x,y;
      cin>>x>>y,x--,y--;

      x=2*x-(n-1);
      y=2*y-(n-1);

      auto _x=M[0][0]*x+M[0][1]*y;
      auto _y=M[1][0]*x+M[1][1]*y;

      G[(_x+n-1)/2][(_y+n-1)/2]++;

      // printf("x %d, y %d\n", x, y);
  
    } else if(z == 2) {

      char c; cin>>c;
      auto R=M;

      if(c == 'A') {
        R[0][0]=0; R[0][1]=1;
        R[1][0]=-1; R[1][1]=0;
      } else {
        R[0][0]=0; R[0][1]=-1;
        R[1][0]=1; R[1][1]=0;
      }

      M=dot(inv(R),M);
      _M=dot(_M,R);
    } else if(z == 3) {

      char c; cin>>c;
      auto F=M;

      if(c == 'A') {
        F[0][0]=-1; F[0][1]=0;
        F[1][0]=0; F[1][1]=1;
      } else {
        F[0][0]=1; F[0][1]=0;
        F[1][0]=0; F[1][1]=-1;
      }

      M=dot(inv(F),M);
      _M=dot(_M,F);
    }
  }

  auto ans=G;

  rep(i,n) {
    rep(j,n) {
      auto _x=_M[0][0]*(2*i-(n-1))+_M[0][1]*(2*j-(n-1));
      auto _y=_M[1][0]*(2*i-(n-1))+_M[1][1]*(2*j-(n-1));
      

      ans[(_x+n-1)/2][(_y+n-1)/2]=G[i][j];
    }
  }

  rep(i,n) {
    rep(j,n) cout<<ans[i][j]%2; cout<<endl;
  }

  return 0;
}
