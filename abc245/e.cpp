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
  vector<ll> a(n),b(n),c(m),d(m);

  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];
  rep(i,m) cin>>c[i];
  rep(i,m) cin>>d[i];

  vector< pair<ll,ll> > aa(n);
  rep(i,n) {
    aa[i].first=a[i];
    aa[i].second=i;
  }

  sort(ALL(aa),greater< pair<ll,ll> >());

  set< pair<ll,ll> > st0,st1;

  rep(i,m) st0.insert({c[i],i});

  // st0.insert({1e18,-1});
  // st1.insert({1e18,-1});

  rep(i,n) {

/*
    printf("aa %lld %lld\n", aa[i].first, aa[i].second);

    cout<<"st0: ";
    for(auto j:st0) cout<<(j.first)<<" "; cout<<endl;

    cout<<"st1: ";
    for(auto j:st1) cout<<(j.first)<<" "; cout<<endl;
*/

    auto index=aa[i].second; // 1

    auto lb0=st0.lower_bound({a[index],-1});


    while(lb0 != st0.end()) {

      auto index0=lb0->second; // 1

      // cout<<"index0: "<<index0<<endl;

      st1.insert({d[index0],index0});

      auto tmp=*(lb0);

      lb0++;

      st0.erase(tmp);
    }


    auto lb1=st1.lower_bound({b[index],-1});

    // cout<<"lb1: "<<lb1->first<<" "<<lb1->second<<endl;

    if(lb1 == st1.end()) {
      cout<<"No"<<endl;
      return 0;
    }

    st1.erase(lb1);
  }

  cout<<"Yes"<<endl;
  return 0;
}
