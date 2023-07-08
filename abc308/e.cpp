# include <bits/stdc++.h>

typedef long long ll;

using namespace std;

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

//////////////////////////////////////////////////////////////////////
/*

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

*/
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// https://atcoder.jp/contests/abc234/editorial/3223 
///*

vector<ll> fac,finv,inv;

void binom_init() {
  const ll MAX=5010;

  fac.resize(MAX);
  finv.resize(MAX);
  inv.resize(MAX);
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<MAX; i++){
      fac[i] = fac[i-1]*i%mod;
      inv[i] = mod-mod/i*inv[mod%i]%mod;
      finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%mod*finv[n-r]%mod;
}

//*/
//////////////////////////////////////////////////////////////////////



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



int main() {
  ll n;
  cin>>n;
  vector<ll>  a(n);
  rep(i,n) cin>>a[i];
  string s; cin>>s;

  vector< vector<ll> > m(n, vector<ll>(3,0));
  vector< vector<ll> > x(n, vector<ll>(3,0));

  if(s[0] == 'M') {
    m[0][a[0]]=1;
  }

  rep(i,n-1) {
    m[i+1]=m[i];
    if(s[i+1] == 'M') {
      m[i+1][a[i+1]]=m[i+1][a[i+1]]+1;
    }
  }

  if(s[n-1] == 'X') {
    x[n-1][a[n-1]]=1;
  }

  for(int i=n-1;i>=1LL;i--) {
    x[i-1]=x[i];
    if(s[i-1] == 'X') {
      x[i-1][a[i-1]]=x[i-1][a[i-1]]+1;
    }
  }
  
  ll ans=0;
  set<ll> st1={0}, st2={0,1}, st3={0,1,2};
  for(ll i=1;i<n-1;i++) {
    if(s[i] != 'E') {
      continue;
    }

    rep(j,3) {
      rep(k,3) {
        set<ll> st={0, 1, 2, 3};
        st.erase(j);
        st.erase(k);
        st.erase(a[i]);

        ans+=(*st.begin())*(m[i-1][j]*x[i+1][k]);

        /*
        if(st == st1) {
          ans+=1*(m[i-1][j]*x[i+1][k]);
        } else if(st == st2) {
          ans+=2*(m[i-1][j]*x[i+1][k]);
        } else if(st == st3) {
          ans+=3*(m[i-1][j]*x[i+1][k]);
        }
        */
      }

    }
  }

  /*
  rep(i,n) cout<<x[i][0]<<" ";
  cout<<endl;
  rep(i,n) cout<<x[i][1]<<" ";
  cout<<endl;
  rep(i,n) cout<<x[i][2]<<" ";
  cout<<endl;
  */
 
  cout<<ans<<endl;
  return 0;
}
