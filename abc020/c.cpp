# include <bits/stdc++.h>
// # include <atcoder/all>

typedef long long ll;

using namespace std;
// using namespace atcoder;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)
#define ALL(a)  (a).begin(),(a).end()

ll gcd(ll x, ll y) { return (x==0)? y : gcd(y%x,x); }
ll lcm(ll x, ll y) { return x/gcd(x,y)*y; }
ll P(ll n, ll k) { return (k==1) ? n : n*(P(n-1,k-1)); }

ll mod=1000000007;
ll comb[2000][2000];
ll nCr(ll n, ll r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
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
  // ll a=1,b=1;
  // for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  // for(int i=0;i<k;i++) b=(b*(k-i))%mod;

  ll a=nCr_mod_memo[n];
  ll b=nCr_mod_memo[n-k];
  ll c=nCr_mod_memo[k];
  ll bc=(b*c)%mod;

  return (a*inv(bc))%mod;
}


ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}


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


ll h,w,t;
vector<string> s;

ll start,goal;
vector< vector< pair<ll,ll> > > G;

bool isok(ll m, ll key) {

  G=vector< vector< pair<ll,ll> > >(h*w);

  for(ll i=0;i<h;i++) {
    for(ll j=0;j<w;j++) {
      if(i-1 >= 0) {
        if(s[i-1][j] == '#') G[i*w+j].emplace_back(m,(i-1)*w+j);
        else G[i*w+j].emplace_back(1,(i-1)*w+j);
      }

      if(i+1 < h) {
        if(s[i+1][j] == '#') G[i*w+j].emplace_back(m,(i+1)*w+j);
        else G[i*w+j].emplace_back(1,(i+1)*w+j);
      }

      if(j-1 >= 0) {
        if(s[i][j-1] == '#') G[i*w+j].emplace_back(m,i*w+j-1);
        else G[i*w+j].emplace_back(1,i*w+j-1);
      }

      if(j+1 < w) {
        if(s[i][j+1] == '#') G[i*w+j].emplace_back(m,i*w+j+1);
        else G[i*w+j].emplace_back(1,i*w+j+1);
      }
    }
  }

  vector<ll> d=dijkstra(G,start);

  // rep(i,h*w) cout<<d[i]<<" "; cout<<endl;

  if(d[goal] <= key) return true;
  else return false;
}


int main() {
  cin>>h>>w>>t;

  s=vector<string>(h);
  rep(i,h) cin>>s[i];

  rep(i,h) rep(j,w) {
    if(s[i][j] == 'S') start=i*w+j;
    else if(s[i][j] == 'G') goal=i*w+j;
  }

  ll ng=1e18,ok=-1;
  while(abs(ok-ng) > 1) {
    ll m=(ok+ng)/2;
    if(isok(m,t)) ok=m;
    else ng=m;
  }

  // cout<<start<<" "<<goal<<endl;
  cout<<ok<<endl;

  return 0;
}
