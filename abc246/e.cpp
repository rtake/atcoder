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


vector<ll> dijkstra(vector< vector< pair<ll,ll> > > G, ll start) {
  ll n=G.size();
  vector<ll> d(n,1e18);
  priority_queue< pair<ll,ll>,
                  vector< pair<ll,ll> >,
                  greater< pair<ll,ll> > > Q;

/*
  d[start]=0;
  Q.emplace(0,start);
*/

  ll nn=n/4;

  rep(i,4) {
    d[start+i*nn]=0;
    Q.emplace(0,start+i*nn);
  }


  while(!Q.empty()) {
    auto u=Q.top();
    Q.pop();

    ll q_u=u.first;
    ll _u=u.second;

    if(d[_u] < q_u) continue;

    for(auto v:G[_u]) {
      ll c_v=v.first;
      ll _v=v.second;

      ll alt=q_u+c_v;

      if(alt < d[_v]) {
        d[_v]=alt;
        Q.emplace(alt,_v);
      }
    }
  }

  return d;
}


int main() {
  ll n;
  cin>>n;
  vector<string> s(n);
  ll ax,ay,bx,by;
  cin>>ax>>ay>>bx>>by;
  ax--,ay--,bx--,by--;

  rep(i,n) cin>>s[i];

  vector< vector< pair<ll,ll> > > G(4*n*n);

  rep(i,n) {
    rep(j,n) {
      if(s[i][j] == '#') continue;

/*
      rep(k,4) {
        if(i+1 < n && j+1 < n & s[i+1][j+1] == '.') {
          if(k == 0LL) G[i*n+j+k*n].emplace_back(0,(i+1)*n+j+1);
          else G[i*n+j+k*n].emplace_back(1,(i+1)*n+j+1);
        }
*/

///*
        rep(k,4) rep(l,4) {
          if(k == l) continue;
          G[i*n+j+k*n*n].emplace_back(1,i*n+j+l*n*n);
        }
//*/

///*
        if(i+1 < n && j+1 < n & s[i+1][j+1] == '.') G[i*n+j+0*n*n].emplace_back(0,(i+1)*n+(j+1)+0*n*n);
        if(i+1 < n && j-1 >= 0LL & s[i+1][j-1] == '.') G[i*n+j+1*n*n].emplace_back(0,(i+1)*n+(j-1)+1*n*n);
        if(i-1 >= 0LL && j+1 < n & s[i-1][j+1] == '.') G[i*n+j+2*n*n].emplace_back(0,(i-1)*n+(j+1)+2*n*n);
        if(i-1 >= 0LL && j-1 >= 0LL & s[i-1][j-1] == '.') G[i*n+j+3*n*n].emplace_back(0,(i-1)*n+(j-1)+3*n*n);
//*/

    }
  }


  ll ans=1e18;


/*
  vector< vector<ll> > D(4);

  rep(i,4) {
    D[i]=dijkstra(G,ax*n+ay+i*n*n);
  }

  


  rep(i,4) {
    rep(j,4) {
      ans=min(ans,D[i][bx*n+by+j*n*n]);
    }
  }


  rep(i,4) {
    for(auto j:D[i]) cout<<j<<" ";
    cout<<endl;
  }
*/

  auto d=dijkstra(G,ax*n*ay);

  for(auto i:d) cout<<i<<" "; cout<<endl;

  rep(i,4) {
    ans=min(ans,d[bx*n+by+i*n*n]);
  }


  if(ans == 1e18) cout<<-1<<endl;
  else cout<<ans+1<<endl;

  return 0;
}
