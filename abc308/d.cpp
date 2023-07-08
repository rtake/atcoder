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
  ll h,w;
  cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s[i];

  string snuke="snuke";
  vector<ll> dx={-1, 0, 1, 0};
  vector<ll> dy={0, -1, 0, 1};

  ll cnt=0;
  deque< pair<ll,ll> > dq;
  dq.push_back({0,0});
  bool ok=false;
  vector<vector<ll>> mat(h, vector<ll>(w, -1));

  while(!dq.empty()) {
    auto _dq=dq;
    dq.clear();

    for(auto p:_dq) {
      auto x=p.first;
      auto y=p.second;

      if(x == h-1 && y == w-1) {
        ok=true;
        break;
      }

      rep(i,4) {
        if(x+dx[i] < 0LL || h <= x+dx[i]) continue;
        if(y+dy[i] < 0LL || w <= y+dy[i]) continue;

        if(s[x+dx[i]][y+dy[i]] == snuke[(cnt+1)%5]) {
          if(mat[x+dx[i]][y+dy[i]] == -1LL) {
            dq.push_back({x+dx[i], y+dy[i]});
            mat[x+dx[i]][y+dy[i]]=cnt;
          }
        }
      }
    }

    cnt++;
  }
/*
  rep(i,h) {
    rep(j,w) {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
*/
  if(ok) cout<<"Yes"<<endl;
  else  cout<<"No"<<endl;

  return 0;
}
