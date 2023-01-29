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
  ll n; cin>>n;
  string s; cin>>s;

  ll cnt1=0;
  multiset<ll> st;
  priority_queue<ll> pq;

  rep(i,n) {
    if(s.substr(i,3) == "ARC") {
  
      ll cnt=1;

      for(ll j=1;i-j>=0;j++) {
        if(s[i-j] == 'A' && s[i+2+j] == 'C') {
          cnt++;
        } else break;
      }

      if(cnt > 1) {
        // pq.push(cnt);
        st.insert(cnt);
      } else cnt1++;

    }
  }


  ll ans=0;

  for(ll i=1;i<=n;i++) {

    // printf("%lld %lld\n", i, cnt1);

    if(i%2 == 1) {

      if(!st.empty()) {

        auto bn=st.begin();
        st.erase(bn);

        if((*bn)-1 > 1) st.insert((*bn)-1);
        else cnt1++;

        ans++;

      } else {

        if(cnt1 > 0) {
          cnt1--;
          ans++;
        } else break;


      }

    } else {

      if(cnt1 > 0) {
        cnt1--;
        ans++;
      } else {

        if(!st.empty()) {
          auto lt=st.end();
          lt--;

          st.erase(lt);
          // cnt1++;
          ans++;

        } else break;

      }

    }

  }

  cout<<ans<<endl;


/*
  ll ans=0;

  for(ll i=1;i<=n;i++) {
    if(i%2 == 0) {

      if(cnt0 > 0) {
        cnt0--;
      } else if(cnt1 > 0) {
        cnt1--;
      } else break;

      ans++;
    } else {

      if(cnt1 > 0) {
        cnt1--;
      } else if(cnt0 > 0) {
        cnt0--;
      } else break;

      ans++;
    }
  }

  cout<<ans<<endl;
*/

  return 0;
}
