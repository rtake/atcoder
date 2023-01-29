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


ll n,m;
vector< vector<ll> > d;
vector< pair<ll,ll> > dd;
set< pair<ll,ll> > st;
vector< vector<bool> > check;

ll f(ll x, ll y) {
  if(d[x][y] >= 0LL) return d[x][y];

  printf("%lld %lld\n", x, y);

  // check[x][y]=true;

  ll tmp=1e18;

  // for(auto p:dd) {
  for(auto p:st) {
    ll dx=p.first;
    ll dy=p.second;

    if((x+dx >= 0LL && x+dx < n) && (y+dy >= 0LL && y+dy < n)) {
      if(check[x+dx][y+dy]) continue;
      // check[x+dx][y+dy]=true;
      tmp=min(tmp,f(x+dx,y+dy)+1);
      // check[x+dx][y+dy]=false;
    }  
  }

  // check[x][y]=false;

  return d[x][y]=tmp;
}


int main() {
  cin>>n>>m;

  d=vector< vector<ll> >(n, vector<ll>(n,-1));
  d[0][0]=0;

  dd=vector< pair<ll,ll> >();
  vector< vector<bool> > check0(n, vector<bool>(n,false));
  check=check0;

  for(ll i=0;i<=m;i++) {
    
    ll ok=0,ng=m+1;
    while(abs(ok-ng) > 1) {
      ll mid=(ok+ng)/2;
      if(i*i+mid*mid <= m) ok=mid;
      else ng=mid;

    }

    if(i*i+ok*ok == m) {
      st.insert({i,ok});
      st.insert({-i,ok});
      st.insert({i,-ok});
      st.insert({-i,-ok});
    }

/*
    if(i*i+ok*ok == m) {
      dd.emplace_back(i,ok);
      dd.emplace_back(-i,ok);
      dd.emplace_back(i,-ok);
      dd.emplace_back(-i,-ok);
    }
*/

  }

/*
  for(auto i:st) {
    printf("%lld %lld\n", i.first, i.second);
  }
*/


/*
  rep(i,n) {
    rep(j,n) {
      f(i,j);
    }
  }
*/

/*
  ll cnt=0;
  deque< pair<ll,ll> > q;
  // set< pair<ll,ll> > st;

  q.push_back({0,0});
  st.insert({0,0});

  while(!q.empty()) {

    deque< pair<ll,ll> > qsub;
    set< pair<ll,ll> > st0;

    auto top=q.front();
    q.pop_front();

    ll x=top.first;
    ll y=top.second;

    d[x][y]=cnt;
    check[x][y]=true;

    for(auto p:st) {
      ll dx=p.first;
      ll dy=p.second;

      if((x+dx >= 0LL && x+dx < n) && (y+dy >= 0LL && y+dy < n)) {

        if(check[x+dx][y+dy]) continue;
        // check[x+dx][y+dy]=true;
        // d[x+dx][y+dy]=cnt;
        qsub.push_back({x+dx,y+dy});

        // st0.insert({x+dx,y+dy})

        printf("%lld %lld\n", x+dx, y+dy);
      }
    }

    q=qsub;
    cnt++;
  }
*/

  
  deque< pair<ll,ll> > q;
  q.push_back({0,0});
  check[0][0]=true;

  ll cnt=0;
  while(!q.empty()) {

    deque< pair<ll,ll> > qsub;

    for(auto p:q) {
      ll x=p.first;
      ll y=p.second;

      // printf("%lld %lld\n", x, y);

      d[x][y]=cnt;

      for(auto pp:st) {
        ll dx=pp.first;
        ll dy=pp.second;

        if((x+dx >= 0LL && x+dx < n) && (y+dy >= 0LL && y+dy < n)) {
          if(check[x+dx][y+dy]) continue;
          check[x+dx][y+dy]=true;
          qsub.push_back({x+dx,y+dy});
        }
      }
    }

    q=qsub;
    cnt++;
  }


  rep(i,n) {
    rep(j,n) cout<<d[i][j]<<" ";
    cout<<endl;
  }

  return 0;
}
