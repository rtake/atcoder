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
  ll n;
  string s;
  cin>>n;
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x[i]>>y[i];
  cin>>s;

  set<ll> st;

  rep(i,n) {
    st.insert(y[i]);
  }

  map<ll,ll> mp;
  vector<ll> yy;
  ll id=0;

  for(auto i:st) {
    yy.push_back(i);
    mp[i]=id;
    id++;
  }

  ll num=yy.size();

  vector< vector<ll> > L(num),R(num);

  rep(i,n) {
    if(s[i] == 'L') {
      L[mp[y[i]]].push_back(x[i]);
    } else {
      R[mp[y[i]]].push_back(x[i]);
    }
  }

  rep(i,num) {
    if(R[i].size() > 0) {
      sort(ALL(R[i]));
/*
      for(auto j:R[i]) cout<<j<<" ";
      cout<<endl;
*/
    }
  }

  rep(i,num) {
    if(L[i].size() > 0) {
      sort(ALL(L[i]));

/*
      for(auto j:L[i]) cout<<j<<" ";
      cout<<endl;
*/
    }
  }

  for(auto p:mp) {
    ll _y=p.second;

    if(R[_y].size() == 0LL) continue;

    for(auto _x:R[_y]) {
      auto lb=lower_bound(ALL(L[_y]),_x);

      if(lb == L[_y].end()) continue;

      if(_x < *lb) {
        cout<<"Yes"<<endl;
        return 0;
      }

    }

  }

  cout<<"No"<<endl;
  return 0;
}
