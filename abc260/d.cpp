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
  ll n,k;
  cin>>n>>k;
  vector<ll> p(n);
  rep(i,n) cin>>p[i], p[i]--;


  vector<ll> cnt(n,0),prev(n,-1),ans(n,-1);
  set<ll> st;


  if(k == 1LL) {

    rep(i,n) {
      ans[p[i]]=(i+1);
    }

    rep(i,n) cout<<ans[i]<<endl;

    return 0;
  }

  st.insert(p[0]);
  cnt[p[0]]=1;

  for(ll i=1;i<n;i++) {

    auto lb=st.lower_bound(p[i]);



    if(lb == st.end()) {
      st.insert(p[i]);

      cnt[p[i]]=1;

      // cout<<"end"<<endl;

    } else {


      cnt[p[i]]=cnt[*(lb)]+1;
      prev[p[i]]=*(lb);

/*
      st.insert(p[i]);
      st.erase(*(lb));
*/

      if(cnt[p[i]] >= k) {

        ll cur=p[i];

        while(cur >= 0LL) {
          ans[cur]=(i+1);
          cur=prev[cur];
        }

      } else {

        st.insert(p[i]);

      }

      st.erase(*(lb));

    }


/*
    if(cnt[p[i]] == k) {
      st.erase(p[i]);
      int cur=p[i];

      rep(j,k) {
        ans[cur]=(i+1);
        cur=prev[cur];
      }

    }
*/

  }


  rep(i,n) {
    if(ans[i] >= 0LL) cout<<ans[i]<<endl;
    else cout<<-1<<endl;
  }

  // for(auto c:cnt) cout<<c<<endl;

  return 0;
}
