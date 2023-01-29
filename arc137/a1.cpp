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
  vector<ll> a(n); rep(i,n) cin>>a[i];

  ll sum=0;
  rep(i,n) sum+=a[i];

  vector<ll> b;

  rep(lt,n) {

    ll rt=lt;

    if(a[lt] == 0LL) {

      while(rt < n) {
        if(rt+1 < n && a[rt+1] == 0LL) rt++;
        else break;
      }

      b.push_back(-(rt-lt+1));

    } else {

      while(rt < n) {
        if(rt+1 < n && a[rt+1] == 1LL) rt++;
        else break;
      }

      b.push_back((rt-lt+1));
    }

    lt=rt;

  }

/*
  for(auto bb:b) cout<<bb<<" "; cout<<endl;
*/


  ll one=1, zero=-1;

  rep(lt,b.size()) {
    ll rt=lt;

    if(b[lt] > 0) {

      ll cnt=b[lt];

      while(rt < b.size()) {
        if(rt+1 >= b.size()) break;

        if(cnt+b[rt+1] < 0) {
          break;
        }

        one=max(one,cnt);

        cnt+=b[rt+1];
        rt++;
      }

      one=max(one,cnt);
    }

    lt=rt;
  }


  rep(lt,b.size()) {
    ll rt=lt;

    if(b[lt] < 0) {

      ll cnt=b[lt];

      while(rt < b.size()) {
        if(rt+1 >= b.size()) break;

        if(cnt+b[rt+1] > 0) {
          break;
        }

        zero=min(zero,cnt);

        cnt+=b[rt+1];
        rt++;
      }

      zero=min(zero,cnt);
    }

    lt=rt;
  }

/*
  printf("zero %lld one %lld\n", zero, one);
*/

  ll _max=min(n,sum+abs(zero));
  ll _min=max(0LL,sum-abs(one));

  cout<<_max-_min+1<<endl;

  return 0;
}
