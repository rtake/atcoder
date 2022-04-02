# include <bits/stdc++.h>
# include <atcoder/all>

typedef long long ll;

using namespace std;
using namespace atcoder;

// using mint=modint1000000007;
using mint=modint998244353;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)
#define fore(i,x) for(auto&& i:x)
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


vector<ll> C,vec;
vector< vector< pair<ll,ll> > > G;

vector<bool> seen;

/*
bool dfs(ll p, ll end) {
    seen[p] = true;

    if (p == end) {
        fore(e, vec) C[e]++;
        return true;
    }
    
    for (auto v:G[p]) {
        if (seen[v.first]) continue;

        vec.push_back(v.second);
        bool b = dfs(v.first, end);

        if (b) return true;

        vec.pop_back();
    }
    return false;
}
*/


///*
bool dfs(ll cur, ll par, ll goal) {

  if(cur == goal) {
    // found=true;
    return true;
  }

  for(auto edge:G[cur]) {
    if(edge.first == par) continue;

    bool res=dfs(edge.first,cur,goal);

    if(res) {
      C[edge.second]++;
      return true;
    }
  }

  return false;
}
//*/


int main() {
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll> a(m);
  rep(i,m) cin>>a[i],a[i]--;

  mod=998244353;

  C=vector<ll>(n-1,0);
  G=vector< vector< pair<ll,ll> > >(n);

  ll u,v;
  rep(i,n-1) {
    cin>>u>>v;
    u--,v--;
    G[u].push_back({v,i});
    G[v].push_back({u,i});
  }

  rep(i,m-1) dfs(a[i],-1,a[i+1]);

  mint cnt0=1; // ll cnt0=1;
  map<ll,mint> mp; // map<ll,ll> mp;

  mp[0]=1;

  rep(i,n-1) {
    map<ll,mint> _mp; // map<ll,ll> _mp;

    if(C[i] > 0) {

      for(auto p:mp) {
        _mp[p.first-C[i]]+=p.second;
        _mp[p.first+C[i]]+=p.second;
      }

      swap(mp,_mp);

    } else {
      cnt0*=2;
    }
  }
  
  cout<<(mp[k]*cnt0).val()<<endl;

/*
  set<ll> st;
  map<ll,ll> mp;

  st.insert(0);
  mp[0]=1;

  ll cnt0=1;

  rep(i,n-1) {
    // if(C[i] == 0LL) continue;

    set<ll> _st;

    for(auto itr:st) {
      _st.insert(itr-C[i]);
      _st.insert(itr+C[i]);

      if(C[i] > 0) {
        mp[itr+C[i]]=(mp[itr+C[i]]+mp[itr])%mod;
        mp[itr-C[i]]=(mp[itr-C[i]]+mp[itr])%mod;
        mp[itr]=0;
      } else {
        // mp[itr]=(mp[itr]*2)%mod;
        cnt0=(cnt0*2)%mod;
      }
    }

    st=_st;
  }

  cout<<(mp[k]*cnt0)%mod<<endl;
*/


/*
  vector<ll> dp(num+10,0);

  rep(i,n-1) {
    if(C[i] == 0LL) continue;


    for(ll j=num;j>=0;j--) {
      if(j-C[i] < 0) continue;
      if(dp[j-C[i]] <= 0) continue;

      dp[j]+=dp[j-C[i]];
    }

    dp[C[i]]++;

    rep(i,num+1) cout<<dp[i]<<" "; cout<<endl;
  }

  ll ans=0;
  for(ll r=k;r<=num;r++) {
    ll b=r-k;
    ans=(ans+dp[r]*dp[b]%mod)%mod;
  }

  cout<<ans<<endl;
*/

  return 0;
}
