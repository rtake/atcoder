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


pair< vector<ll>, vector<bool> > bellman_ford
(vector< vector< pair<ll,ll> > > G, ll start) {
  ll inf=1e18;

  ll n=G.size();

  vector<ll> d(n,inf);
  vector<bool> negative(n,false);

  d[start]=0;

  for(ll i=0;i<n-1;i++) {
    for(ll j=0;j<n;j++) {
      for(auto edge:G[j]) {
        ll from=j,to=edge.second,cost=edge.first;

        if(d[from] != inf && d[to] > d[from]+cost) {
          d[to]=d[from]+cost;
        }
      } // for all edges
    } // for all nodes
  } 


  for(ll j=0;j<n;j++) {
    for(auto edge:G[j]) {
      ll from=j,to=edge.second,cost=edge.first;

      if(d[from] != inf && d[to] > d[from]+cost) {
        d[to]=d[from]+cost;
        negative[to]=true;
      }

      if(negative[from]) negative[to]=true;
    } // for all edges
  } // for all nodes
  
  return make_pair(d,negative);
}


pair< vector<ll>, vector<bool> > bellman_ford
(ll n, vector< pair< pair<ll,ll>, ll> > V, ll start) {
  ll inf=1e18;

  vector<ll> d(n,inf);
  vector<bool> negative(n,false);

  d[start]=0;

  for(ll i=0;i<n-1;i++) {
    for(auto edge:V) {
      auto p=edge.first;
      ll from=p.first;
      ll to=p.second;
      ll cost=edge.second;

      if(d[from] != inf && d[to] > d[from]+cost) d[to]=d[from]+cost;
    } // for all edge
  }


  for(ll i=0;i<n-1;i++) {
    for(auto edge:V) {
      auto p=edge.first;
      ll from=p.first;
      ll to=p.second;
      ll cost=edge.second;

      if(d[from] != inf && d[to] > d[from]+cost) {
        d[to]=d[from]+cost;
        negative[to]=true;
      }

      if(negative[from]) negative[to]=true;
    } // for all edges
  }

  return make_pair(d,negative);
}


int main() {
  ll n,m,p;
  cin>>n>>m>>p;

  vector< vector< pair<ll,ll> > > G(n);
  vector< pair< pair<ll,ll>,ll > > V;

  ll a,b,c;
  rep(i,m) {
    cin>>a>>b>>c;
    a--,b--;

    G[a].emplace_back(-(c-p),b);

    V.push_back({make_pair(a,b),-(c-p)});
  }

  // auto v=bellman_ford(G,0);

  auto v=bellman_ford(n,V,0);
  auto d=v.first;
  auto negative=v.second;

  // if(negative[n-1]) cout<<-1<<endl;
  // else cout<<max(0LL,-d[n-1])<<endl;

  cout<<(negative[n-1] ? -1 : max(0LL,-d[n-1]))<<endl;

  return 0;
}
