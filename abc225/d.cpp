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


int main() {
  int n,q;
  cin>>n>>q;

  int c,x,y;
  vector<int> next(n,-1), root(n,-1), prev(n,-1);

  rep(i,n) root[i]=i;
  // rep(i,n) cout<<next[i]<<" "; cout<<endl;


  rep(i,q) {
    cin>>c;

    if(c == 1) {
      cin>>x>>y;
      x--,y--;

      root[y]=root[x];
      next[x]=y;

      prev[y]=x;

    } else if(c == 2) {
      cin>>x>>y;
      x--,y--;

      next[x]=-1;
      root[y]=y;

      prev[y]=-1;

/*
      int cur=y;
      while(cur >= 0) {
        root[cur]=y;
        cur=next[cur];
      }
*/

    } else if(c == 3) {
      cin>>x;
      x--;

      deque<int> dq;

      int cur=x;
      while(cur >= 0) {
        dq.push_front(cur);
        cur=prev[cur];
      }

      cur=next[x];
      while(cur >= 0) {
        dq.push_back(cur);
        cur=next[cur];
      }

/*
      vector<int> ans;
      int cur=root[x];
      // cout<<"root "<<root[x]<<endl;

      while(cur != root[cur]) {
        cur=root[cur];
      }

      while(cur >= 0) {
        ans.push_back(cur);
        cur=next[cur];
      }
*/

      cout<<dq.size()<<" ";
      for(auto itr:dq) cout<<itr+1<<" ";
      cout<<endl;
    }

    // rep(j,n) cout<<next[j]+1<<" "; cout<<endl;
    // rep(j,n) cout<<root[j]+1<<" "; cout<<endl;
  }

  return 0;
}
