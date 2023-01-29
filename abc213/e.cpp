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


int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

int ddr[8]={-1,-1,-1,0,1,1,1,0};
int ddc[8]={-1,0,1,1,1,0,-1,-1};


int main() {
  int h,w;
  cin>>h>>w;

  vector<string> s(h);

  rep(i,h) cin>>s[i];

  vector< vector <bool > > check(h, vector<bool>(w,false));
  vector< vector <ll> > D(h, vector<ll>(w,1e18));

  deque< pair<ll,ll> > dq;

  dq.emplace_back(0,0);
  D[0][0]=0;

  while(!dq.empty()) {
    auto top=dq.front();
    dq.pop_front();

    ll d=top.first;
    ll r=(top.second)/w;
    ll c=(top.second)%w;

    // printf("%lld %lld\n", r, c);

    rep(i,4) {
      ll _r=r+dr[i];
      ll _c=c+dc[i];

      if(!(_r >= 0LL && _r < h)) continue;
      if(!(_c >= 0LL && _c < w)) continue;

      if(s[_r][_c] == '.') {
        if(D[_r][_c] > d) {
          D[_r][_c]=d;
          dq.emplace_front(d,_r*w+_c);
        }
      } else {

        if(D[_r][_c] <= d) continue;

        rep(j,8) {
          ll __r=_r+ddr[j];
          ll __c=_c+ddc[j];
        
          if(!(__r >= 0LL && __r < h)) continue;
          if(!(__c >= 0LL && __c < w)) continue;

          if(D[__r][__c] > d+1) {
            D[__r][__c]=d+1;
            dq.emplace_back(d+1,__r*w+__c);
          }
        }
      }
    }
  }

  cout<<D[h-1][w-1]<<endl;

/*
  rep(i,h) {
    rep(j,w) cout<<D[i][j]<<" "; cout<<endl;  
  }
*/

  return 0;
}