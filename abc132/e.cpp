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


int main() {
  ll n,m,s,t;
  cin>>n>>m;

  vector< vector< pair<ll,ll> > > G(n);

  ll u,v;
  rep(i,m) {
    cin>>u>>v;
    u--,v--;
    // G[v].emplace_back(1,u);
    G[u].emplace_back(1,v);
  }

  cin>>s>>t;
  s--,t--;

  vector< vector< pair<ll,ll> > > G0(n);

  auto d0=dijkstra(G,s);
  vector<ll> d1(n,-1),d2(n,-1);

  rep(i,n) {
    if(d0[i]%3 == 0LL && i != s) {
      G0[s].emplace_back(d0[i]/3,i);
    }
  }


  rep(i,n) {
    if(d0[i] == 1LL) {
      d1=dijkstra(G,i);

      rep(j,n) {
        if(d1[j]%3 == 0LL && j != i) {
          G0[i].emplace_back(d1[j]/3,j);
        }
      }

      // cout<<"d1 "<<i<<endl;


      break;
    }
  }

  rep(i,n) {
    if(d0[i] == 2LL) {
      d2=dijkstra(G,i);

      rep(j,n) {
        if(d2[j]%3 == 0LL && j != i) {
          G0[i].emplace_back(d2[j]/3,j);
        }
      }


      break;
    }
  }

  for(ll i=0;i<n;i++) {
    cout<<i<<endl;

    for(auto v:G0[i]) {
      cout<<v.first<<" "<<v.second<<endl;
    }
  }

  auto dd=dijkstra(G0,s);

  for(auto i:dd) cout<<i<<" "; cout<<endl;

  if(dd[t] < 1e18) cout<<dd[t]<<endl;
  else cout<<-1<<endl;

  return 0;
}
