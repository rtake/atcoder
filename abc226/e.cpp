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


vector< vector<ll> > G;

int main() {
  ll n,m;
  cin>>n>>m;

  G=vector< vector<ll> >(n);
  
  ll u,v;
  rep(i,m) {
    cin>>u>>v;
    u--,v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  mod=998244353;

  ll ans=1;
  vector<ll> checked(n,0);

  rep(i,n) {
    if(checked[i] > 0) continue;

    map<ll,ll> mp;
    deque<ll> dq;
    dq.push_back(i);

    ll cur,prev=-1;

    while(!dq.empty()) {
      cur=dq.front();
      dq.pop_front();

      printf("cur %lld, prv %lld\n", cur, prev);

      for(auto v:G[cur]) {
        if(prev == v) continue;

        if(mp[v] > 0) {
          mp[v]++;
        } else {
          mp[v]=1;
          dq.push_back(v);
        }
      }

      prev=cur;
    }

    ll cnt=0;

    cout<<endl;

    for(auto x:mp) {
      if(x.second == 2) cnt++;
      checked[x.first]=true;

      cout<<x.first<<" "<<x.second<<endl;
    }


    if(cnt == 0) ans*=0;
    else {
      rep(i,cnt) ans=(ans*2)%mod;
    }
  }

  cout<<ans<<endl;

  return 0;
}
