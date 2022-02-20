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


ll n;
ll ans;
vector< vector< pair<ll,ll> > > G;

struct S{
  ll val;
  ll size;
};

using F=ll;

S op(S a,S b) { return S{a.val+b.val,a.size+b.size}; }
S e() { return S{0,0}; }

S mapping(F f, S x) { 
  if(x.val == 0LL) return S{0,x.size};
  else return S{x.val^f,x.size};
}

ll composition(F f, F g) { return g^f; }
ll id() { return 0; }

lazy_segtree<S,op,e,F,mapping,composition,id> seg;

void dfs(ll cur, ll par=-1) {
  // seg.set(cur,S{0,1});


  for(auto node:G[cur]) {
    if(node.second == par) continue;

    seg.apply(0,n,node.first);

    seg.set(cur,S{node.first,1});

    // ans=(ans+seg.all_prod().val)%mod;

///*
    rep(i,n) cout<<seg.get(i).val<<" "; cout<<endl;
    printf("cur %lld, ans %lld, all_prod %lld, prod %lld\n\n", cur, ans, seg.all_prod().val, seg.prod(0,n).val);
//*/

    ll sum=0;
    rep(i,n) sum+=seg.get(i).val;
    // cout<<sum<<endl;

    ans=(ans+sum)%mod;

    dfs(node.second,cur);

    seg.apply(0,n,node.first);

    seg.set(node.second,S{node.first,1});
  }

}



int main() {
  cin>>n;

  ll u,v,w;
  G=vector< vector< pair<ll,ll> > >(n);
  rep(i,n-1) {
    cin>>u>>v>>w;
    u--,v--;
    G[v].emplace_back(w,u);
    G[u].emplace_back(w,v);
  }

  ans=0;

  vector<S> a(n,S{0,1});
  seg=lazy_segtree<S,op,e,F,mapping,composition,id>(a);

  rep(i,n) {
    sort(ALL(G[i]));
  }

  dfs(n-1);

  cout<<ans<<endl;

  return 0;
}
