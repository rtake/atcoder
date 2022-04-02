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

  d[start]=0;
  Q.emplace(0,start);

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


ll n,m,k;
vector< vector<ll> > D,dp;


ll dfs(ll k0, ll index) {
  if(dp[k0][index] >= 0LL) return dp[k0][index];

  dp[k0][index]=0;

  rep(i,n) {
    if(k0-D[i][index] < 0) continue;
    if(i == index) continue;

    dfs(k0-D[i][index],i);

    dp[k0][index]+=dp[k0-D[i][index]][i];
    dp[k0][index]%=mod;
  }

  return dp[k0][index];
}


int main() {
  cin>>n>>m>>k;

  mod=998244353;

  set< pair<ll,ll> > st;
  ll u,v;

  rep(i,m) {
    cin>>u>>v;
    u--,v--;
    st.insert({u,v});
  }

  vector< vector< pair<ll,ll> > > G(n);

  rep(i,n) {
    rep(j,n) {
      if(i == j) continue;
      if(st.find({min(i,j),max(i,j)}) == st.end()) {
        G[i].emplace_back(1,j);
        G[j].emplace_back(1,i);
      }
    }
  }

  
  D=vector< vector<ll> >(n, vector<ll>(n,1));

  rep(i,n) D[i][i]=1e18;

  for(auto p:st) {
    D[p.first][p.second]=D[p.second][p.first]=1e18;
  }

  // rep(i,n) D[i]=dijkstra(G,i);


  dp=vector< vector<ll> >(k+10, vector<ll>(n,-1));

  rep(i,n) dp[0][i]=0;
  dp[0][0]=1;

  dfs(k,0);

/*
  rep(i,n) {
    rep(j,k+1) cout<<dp[j][i]<<" "; cout<<endl;
  }
*/

  cout<<dp[k][0]<<endl;  

  return 0;
}
