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

vector<ll> x;
vector< vector<ll> > G;
vector< pair<ll,ll> > M;
vector< priority_queue< pair<ll,ll> > > PQ;

void dfs(ll cur, ll par=-1) {
  M[cur]=make_pair(-1,cur);

  priority_queue< pair<ll,ll> > PQ0;

  // PQ0.push(make_pair(x[cur],cur));
  // PQ[cur].push(make_pair(x[cur],cur));

  for(auto node:G[cur]) {
    if(node == par) continue;

    dfs(node,cur);

    if(M[cur].first < M[node].first) {
      M[cur].first=M[node].first;
      M[cur].second=node;
    }


    PQ0.push({M[node].first,node});
  }


  rep(i,20) {
    if(PQ0.empty()) break;

    auto p=PQ0.top();
    PQ0.pop();

    PQ[cur].push({p.first,cur});

    PQ[p.second].pop();

    if(!PQ[p.second].empty()) {
      PQ0.push({PQ[p.second].top().first,p.second});
      PQ[p.second].pop();
    }
  }


  PQ[cur].push({x[cur],cur});

  if(M[cur].first == -1LL) M[cur].first=x[cur];
}

int main() {
  ll n,q;
  cin>>n>>q;

  x=vector<ll>(n);

  vector<ll> a(n-1),b(n-1),v(q),k(q);
  rep(i,n) cin>>x[i];
  rep(i,n-1) cin>>a[i]>>b[i],a[i]--,b[i]--;
  rep(i,q) cin>>v[i]>>k[i],v[i]--;

  M=vector< pair<ll,ll> >(n);
  G=vector< vector<ll> >(n);
  PQ=vector< priority_queue< pair<ll,ll> > >(n);

  rep(i,n-1) {
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  queue<ll> Q;
  Q.push(0);

  ll cur=0;
  vector<bool> arrived(n,false);

  while(!Q.empty()) {
    cur=Q.front(); Q.pop();
    arrived[cur]=true;

    for(auto itr:G[cur]) {
      if(arrived[itr]) continue;
      // PQ[cur].push(make_pair(x[itr],itr));
      Q.push(itr);
    }
  }

  dfs(0);


  // rep(i,n) cout<<M[i].first<<" "<<M[i].second<<endl;

  rep(i,n) {
    if(PQ[i].empty()) {
      cout<<endl;
      continue;
    }

    auto PQ0=PQ[i];
    
    while(!PQ0.empty()) {
      cout<<PQ0.top().first<<","<<PQ0.top().second<<" ";
      PQ0.pop();
    }

    cout<<endl;
  }

/*
  rep(i,q) {
    auto PQ0=PQ[v[i]];

    rep(j,k[i]-1) {
      cout<<PQ0.top().first<<" ";
      PQ0.pop();
    }

    cout<<endl;

    // cout<<PQ0.top().first<<endl;
  }
*/

  return 0;
}
