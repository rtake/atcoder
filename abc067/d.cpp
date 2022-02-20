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


int n;
vector< vector<int> > G;
vector<int> black_or_white;
vector< vector<bool> > results, is_checked;

bool dfs(int cur,int turn) {
  if(is_checked[cur][turn]) return results[cur][turn];
  is_checked[cur][turn]=is_checked[cur][(turn+1)%2]=true;
  // is_checked[cur][turn]=true;

  bool win=false;

/*
  cout<<endl;
  rep(i,n) {
    rep(j,2) { cout<<results[i][j]<<"("<<is_checked[i][j]<<")"; }
    cout<<endl;
  }
*/

  // rep(i,n) cout<<black_or_white[i]<<" "; cout<<endl;

  for(int i=0;i<n;i++) {
    if(black_or_white[i] == turn) {
      for(auto v:G[i]) {
        if(black_or_white[v] == -1) {
          black_or_white[v]=turn;
          win|=!dfs(v,(turn+1)%2);
          black_or_white[v]=-1;
        }
      }
    }
  }

/*
  for(auto v:G[cur]) {
    if(is_checked[v][(turn+1)%2]) continue;
    win|=!dfs(v,(turn+1)%2);
  }
*/

  // rep(i,n) cout<<black_or_white[i]<<" "; cout<<turn<<" "<<win<<endl;

  results[cur][turn]=win;
  results[cur][(turn+1)%2]=!win;

  return win;
}

int main() {
  cin>>n;

  G=vector< vector<int> >(n);

  int a,b;
  rep(i,n-1) {
    cin>>a>>b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  black_or_white=vector<int>(n,-1);
  black_or_white[0]=0; // black
  black_or_white[n-1]=1; // white

  results=vector< vector<bool> >(n, vector<bool>(2,false));
  is_checked=vector< vector<bool> >(n, vector<bool>(2,false));

  bool win=dfs(0,0);

/*
  cout<<endl;
  rep(i,n) {
    rep(j,2) { cout<<results[i][j]<<"("<<is_checked[i][j]<<")"; }
    cout<<endl;
  }
*/

  if(win) cout<<"Fennec"<<endl; 
  else cout<<"Snuke"<<endl;

  return 0;
}
