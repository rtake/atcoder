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


string s;
int n;


ll dfs(int S, bool is_small, int pos) {
  if(pos == n-1) {
    int cnt=0;

    if(S%2 == 1) cnt++;
    if((S>>1)%2 == 1) cnt++;
    if((S>>2)%2 == 1) cnt++;

    printf("cnt %d S %d\n", cnt, S);

    if(cnt == 3) return 3;
    else if(cnt == 2) return 1;
    else return 0;
  }

  // ll res=dfs(S,false,pos+1);
  ll res=0;

  if(is_small) {
    // res+=dfs(S+1,true,pos+1)+dfs(S+2,true,pos+1)+dfs(S+4,true,pos+1);
    // printf("S %d bool %d pos %d res %lld\n", S, is_small, pos, res);
    // return res;
  }

  res+=dfs(S,false,pos+1);

  if(s[pos]-'0' < 3) {
    // res=dfs(S,true,pos+1);
  } else if(s[pos]-'0' == 3) {
    res+=dfs(S|1,false,pos+1);
  } else if(s[pos]-'0' < 5) {
    res+=dfs(S+1,true,pos+1);
  } else if(s[pos]-'0' == 5) {
    res+=dfs(S|1,true,pos+1)+dfs(S|2,false,pos+1);
  } else if(s[pos]-'0' < 7) {
    res+=dfs(S+1,true,pos+1)+dfs(S+2,true,pos+1);
  } else if(s[pos]-'0' == 7) {
    res+=dfs(S+1,true,pos+1)+dfs(S+2,true,pos+1)+dfs(S+4,false,pos+1);
  } else {
    res+=dfs(S+1,true,pos+1)+dfs(S+2,true,pos+1)+dfs(S+4,true,pos+1);
  }

  printf("S %d bool %d pos %d res %lld\n", S, is_small, pos, res);
  return res;
}


int main() {
  cin>>s;
  n=s.length();

  ll res=dfs(0,false,0);
  cout<<res<<endl;

  return 0;
}
