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


int main() {
  ll n;
  cin>>n;

  vector< deque< pair<ll,ll> > > m(n);

  rep(i,n) {
    rep(j,n-1) {
      ll a;
      cin>>a;
      a--;
      m[i].emplace_back(min(i,a),max(i,a));
    }
  }

  map< pair<ll,ll>,ll > mp;
  ll ans=0;

  do {

  for(ll i=0;i<n;i++) {
    vector<bool> have_match(n,false);
    auto top=m[i].front();

    if(mp.find(top) != mp.end()) {
      ll index=mp[top];
      mp.erase(top);

      if(m[i].size() >= 1) m[i].pop_front();
      // if(m[i].size() >= 1) mp[m[i].front()]=i;

      if(m[index].size() >= 1) m[index].pop_front();
      // if(m[index].size() >= 1) mp[m[index].front()]=index;

      if(have_match[i] || have_match[index]) ans++;
      have_match[i]=have_match[index]=true;
    } else {
      mp[top]=i;
    }
  }

  if(mp.size() == n) {
    cout<<-1<<endl;
    return 0;
  }

    cout<<endl<<"ans "<<ans<<endl;
    ans++;
  } while(!mp.empty());

  cout<<ans<<endl;

  return 0;
}
