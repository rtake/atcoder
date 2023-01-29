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

//////////////////////////////////////////////////////////////////////
/*

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

*/
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// https://atcoder.jp/contests/abc234/editorial/3223 
///*

vector<ll> fac,finv,inv;

void binom_init() {
  const ll MAX=5010;

  fac.resize(MAX);
  finv.resize(MAX);
  inv.resize(MAX);
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<MAX; i++){
      fac[i] = fac[i-1]*i%mod;
      inv[i] = mod-mod/i*inv[mod%i]%mod;
      finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%mod*finv[n-r]%mod;
}

//*/
//////////////////////////////////////////////////////////////////////



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
  ll h,w; cin>>h>>w;
  vector<string> c(h);
  rep(i,h) cin>>c[i];

  ll start;

  rep(i,h) {
    rep(j,w) {
      if(c[i][j] == 'S') {
        start=i*w+j;
      }
    }
  }

  vector<ll> dx,dy;
  dx.push_back(-1); dy.push_back(0);
  dx.push_back(0); dy.push_back(1);
  dx.push_back(1); dy.push_back(0);
  dx.push_back(0); dy.push_back(-1);

  deque<ll> dq;
  dq.push_back(start);

  vector< vector<ll> > dp(h, vector<ll>(w,-1));
  dp[start/w][start%w]=0;

  vector< vector<ll> > ddp(h, vector<ll>(w,-1));
  ddp[start/w][start%w]=0;

  ll x=start/w;
  ll y=start%w;

  rep(i,4) {
    ll xx=(start/w)+dx[i];
    ll yy=(start%w)+dy[i];

    if(xx < 0LL || xx > h-1) continue;
    if(yy < 0LL || yy > w-1) continue;
    if(xx == x && yy == y) continue;
    if(c[xx][yy] != '.') continue;

    dp[xx][yy]=1;
    ddp[xx][yy]=i+1;

    rep(j,4) {
      ll xxx=xx+dx[j];
      ll yyy=yy+dy[j];

      if(xxx < 0LL || xxx > h-1) continue;
      if(yyy < 0LL || yyy > w-1) continue;
      if(xxx == x && yyy == y) continue;
      if(c[xxx][yyy] != '.') continue;
      if(abs(xxx-x) == 1LL && abs(yyy-y) == 1LL) continue;
      
      dp[xxx][yyy]=2;
      ddp[xxx][yyy]=i+1;

      dq.push_back(xxx*w+yyy);
    }

  }



  while(!dq.empty()) {

    auto top=dq.front();
    dq.pop_front();

    ll x=top/w;
    ll y=top%w;

    rep(i,4) {
      ll xx=x+dx[i];
      ll yy=y+dy[i];

      if(xx < 0LL || xx > h-1) continue;
      if(yy < 0LL || yy > w-1) continue;
      if(xx == x && yy == y) continue;
      if(c[xx][yy] != '.') continue;

      if(dp[xx][yy] >= 0LL) {
        if(dp[x][y]+dp[xx][yy] >= 4LL && ddp[x][y] != ddp[xx][yy]) {
          cout<<"Yes"<<endl;

/*
          printf("%lld %lld\n", x, y);
          printf("%lld %lld\n", xx, yy);

          rep(i,h) {
            rep(j,w) {
              cout<<dp[i][j]<< "\t";
            }
 
            cout<<endl;
          }

          rep(i,h) {
            rep(j,w) {
              cout<<ddp[i][j]<< "\t";
            }
 
            cout<<endl;
          }
*/
//*/

          return 0;
        }
      } else {
        dp[xx][yy]=dp[x][y]+1;
        dq.push_back(xx*w+yy);

        if(ddp[x][y] == 0LL) ddp[xx][yy]=i+1;
        else ddp[xx][yy]=ddp[x][y];
      }

    }

  }


/*
          rep(i,h) {
            rep(j,w) {
              cout<<dp[i][j]<< "\t";
            }
 
            cout<<endl;
          }
*/


  cout<<"No"<<endl;

  return 0;
}
