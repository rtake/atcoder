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
  vector<ll> A(n);
  rep(i,n) cin>>A[i];

  vector<ll> B,C;
  for(auto i:A) {
    if(i >= 0LL) B.push_back(abs(i));
    else C.push_back(abs(i));
  }

  sort(ALL(B));
  sort(ALL(C));

  if(B.size() < C.size()) swap(B,C); // B > C

  ll b=B.size();
  ll c=C.size();

  vector<ll> v;

  if(k <= b*c) {

    ll cnt=0;
    for(ll i=1;i<=b+c-1;i++) {
      if(i <= c) {
        if(k <= cnt+i) {
          rep(j,i) v.push_back(-B[b-i+j]*C[j]);
          break;
        }
        
        cnt+=i;
      } else if(i <= b) {
        if(k <= cnt+c) {
          rep(j,c) v.push_back(-B[b-i+j]*C[j]);
          break;
        }

        cnt+=c;
      } else {
        if(k <= cnt+(b+c-i)) {
          rep(j,(b+c-i)) v.push_back(-B[j]*C[j-(b-i)]);
          break;
        }

        cnt+=(b+c-i);
      }
    }

    sort(ALL(v));

    cout<<v[(k-cnt)-1]<<endl;
  } else {
    vector<ll> _B(b),_C(c);
    
    rep(i,b) _B[i]=B[i]*B[0];
    rep(i,c) _C[i]=C[i]*C[0];

    ll index=0;
    for(ll i=1;i<b;i++) {
      index=lower_bound(ALL(_C),_B[i])-_C.begin()-1;

      if(k <= b*c+i*(i+1)/2+index*(index+1)/2) {
        rep(j,i) v.push_back(B[j]*B[i-j]);
        rep(j,index) v.push_back(C[j]*C[index-j]);

        sort(ALL(v));

        cout<<v[(k-(b*c+i*(i-1)/2+index*(index-1)/2))-1]<<endl;

        for(auto i:v) cout<<i<<endl;

        return 0;
      }
    }

    for(ll i=index;i<c;i++) {
      if(k <= b*c+b*(b-1)/2+i*(i+1)/2) {
        rep(j,i) v.push_back(C[j]*C[i-j]);

        sort(ALL(v));

        cout<<v[(k-(b*c+b*(b-1)/2+i*(i-1)/2))-1]<<endl;

        for(auto i:v) cout<<i<<endl;

        return 0;
      }

    }
  }

  // for(auto i:v) cout<<i<<endl;

  return 0;
}
