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


/*
ll binpower(ll a, ll b) {
  ll ans=1;
  while (b != 0) {
    if (b%2 == 1) ans = (ans*a)%mod;
    a=(a*a)%mod;
    b/=2;
  }
  return ans;
}
*/


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


// https://drken1215.hatenablog.com/entry/2019/02/15/141000#fn:1
vector< vector< pair<ll,ll> > > G;
set<pair<int,int> > use;

vector<ll> dijkstra(vector< vector< pair<ll,ll> > > G, ll start) {
  vector<ll> dist((ll)G.size(),1e18);
  vector< vector<ll> > prev((ll)G.size());
  priority_queue< pair<ll,ll>,
                  vector< pair<ll,ll> >,
                  greater< pair<ll,ll> > > Q;

  dist[start]=0;
  Q.emplace(0,start);

  while(!Q.empty()) {
    auto cur=Q.top(); Q.pop();
    ll cur_d=cur.first;
    ll cur_v=cur.second;

    if(dist[cur_v] < cur_d) continue; // 枝狩り

    for(auto next:G[cur_v]) {
      ll next_d=next.first;
      ll next_v=next.second;

      ll alt=cur_d+next_d;

      if(alt < dist[next_v]) {
        dist[next_v]=alt;
        Q.emplace(alt,next_v);

        prev[next_v].clear();
        prev[next_v].push_back(cur_v);
      } else if(alt == dist[next_v]) {
        prev[next_v].push_back(cur_v);
      }
    }
  }

  for(ll v=0;v<(ll)G.size();v++) {
    for(auto u:prev[v]) {
      use.insert(make_pair(min(u,v),max(u,v)));
    }
  }

  return dist;
}


int main() {
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s[i];

  G=vector< vector< pair<ll,ll> > >(h*w);

  rep(i,h) rep(j,w) {
    if(i+1 < h && s[i][j] != s[i+1][j]) {
      G[i*w+j].emplace_back(1,(i+1)*w+j);
      G[(i+1)*w+j].emplace_back(1,i*w+j);
    }

    if(j+1 < w && s[i][j] != s[i][j+1]) {
      G[i*w+j+1].emplace_back(1,i*w+j);
      G[i*w+j].emplace_back(1,i*w+j+1);
    }
  }


  ll ans=0;

  rep(i,h) rep(j,w) {
    auto d=dijkstra(G,i*w+j);

    for(ll k=i*w+j+1;k<h*w;k++) {
      if(d[k] < 1e18 && s[i][j] != s[k/w][k%w]) ans++;
    }
  }

  cout<<ans<<endl;

  return 0;
}
