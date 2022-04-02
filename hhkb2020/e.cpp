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
  ll h,w;
  cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s[i];

  ll m=h*w;
  vector< vector<ll> > R(w),C(h);

  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == '#') {
        R[j].push_back(i);
        C[i].push_back(j);
        m--;
      }
    }
  }

  rep(i,h) {
    C[i].push_back(-1e18);
    C[i].push_back(1e18);
    sort(ALL(C[i]));
  }

  rep(j,w) {
    R[j].push_back(-1e18);
    R[j].push_back(1e18);
    sort(ALL(R[j]));
  }

  vector<ll> bin(2000*2000+2000,0);
  rep(i,2000*2000+2000) bin[i]=binpower(2,i,mod);

  ll ans=0;

  rep(i,h) {
    rep(j,w) {
      if(s[i][j] != '.') continue;

      auto x=lower_bound(ALL(C[i]),j);
      auto y=lower_bound(ALL(R[j]),i);

      ll left,right,up,down;

      left=max(*(x-1)+1,0LL);
      right=min(*x,w)-1;

      up=max(*(y-1)+1,0LL);
      down=min(*y,h)-1;


      ll num=(right-left+1)+(down-up+1)-1;

      // ans=(ans+(binpower(2,num,mod)-1)*(binpower(2,m-num,mod)))%mod;
      ans=(ans+(bin[num]-1)*(bin[m-num]))%mod;

      // printf("%lld %lld %lld %lld\n", left, right, up, down);
      // cout<<ans<<endl;
    }
  }

  cout<<ans<<endl;

/*
  rep(i,h) {
    for(auto j:C[i]) cout<<j<<" "; cout<<endl;
  }


  rep(i,w) {
    for(auto j:R[i]) cout<<j<<" "; cout<<endl;
  }
*/

  return 0;
}
