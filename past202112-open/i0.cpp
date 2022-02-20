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



int main() {
  ll n,m;
  cin>>n>>m;
  vector<ll> a(m),b(m),c(m);
  rep(i,m) cin>>a[i]>>b[i]>>c[i]; //,a[i]--,b[i]--;

  vector< pair<ll,ll> > v(m);
  rep(i,m) {
    v[i].first=a[i];
    v[i].second=b[i];    
  }

  map< pair<ll,ll>,ll > cost;
  rep(i,m) cost[v[i]]=c[i];

  rep(i,m) swap(v[i].first,v[i].second);
  sort(ALL(v));
  rep(i,m) swap(v[i].first,v[i].second);

  map<ll,ll> mp;
  vector<ll> u;
  set<ll> st,_st;

  mp[1]=0;
  mp[1e18]=1e18-1;

  rep(i,m) {
    mp[v[i].first]=v[i].first-1;
    mp[v[i].second]=v[i].second-1;
  }

  st.insert(-1);
  _st.insert(1e18+1);

  // st.insert(1e18);
  // _st.insert(-1e18);

  // u.push_back(1);

  rep(i,m) {
    auto _a=v[i].first;
    auto _b=v[i].second;

    auto lb=st.lower_bound(-_a);
    auto _lb=_st.lower_bound(_a);

    // printf("_a %lld, lb %lld\n", _a, *lb);
    // printf("_a %lld, _lb %lld\n", _a, *_lb);
    
    mp[_a]=min(mp[_a],mp[-(*lb)]+((*lb)+_a));
    mp[_a]=min(mp[_a],mp[*_lb]+(*_lb-_a));

    // mp[_a]=min(mp[_a],_a-1);
    // mp[_a]=min(mp[*lb]+(_a-(*lb)),mp[-(*_lb)]+(-_a-(*_lb)));

    // mp[_b]=min(mp[_b],_b-1);
    mp[_b]=min(mp[_b],mp[_a]+cost[v[i]]);
    mp[_b]=min(mp[_b],mp[-(*st.begin())]+(*st.begin())+_b);

    // cout<<(*st.begin())<<endl;

    // for(auto itr:st) cout<<itr<<" "; cout<<endl;

    st.insert(-_a);
    st.insert(-_b);

    _st.insert(_a);
    _st.insert(_b);

/*
    for(auto itr:mp) {
      cout<<itr.first<<" "<<itr.second<<endl;
    }
*/
  }

/*
  for(auto itr:mp) {
    cout<<itr.first<<" "<<itr.second<<endl;
  }
*/  
/*
  auto lb=st.lower_bound(-n);
  cout<<mp[-(*lb)]+(n-(-(*lb)))<<endl;
*/

  ll ans=n-1;
  for(auto itr:st) {
    ans=min(ans,mp[-itr]+(n-(-itr)));
  }

  cout<<ans<<endl;

  return 0;
}
