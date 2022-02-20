# include <bits/stdc++.h>
//# include <atcoder/all>

typedef long long lint;
typedef long long ll;

using namespace std;
//using namespace atcoder;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint mod=1000000007;
lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

lint inv(lint x) {
  lint res=1, k=mod-2;
  while(k>0) {
    if(k&1 == 1) res=(res*x)%mod;
    x=(x*x)%mod;
    k/=2;
  }
  return res;
}

lint nCr_mod(lint n, lint k) {
  lint a=1,b=1;
  for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  for(int i=0;i<k;i++) b=(b*(k-i))%mod;
  return (a*inv(b))%mod;
}

// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }

/*
struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { 
        int rx = root(x); 
        int ry = root(y); 
        if (rx == ry) return; 
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
*/


// https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
struct UnionFind {
  vector<ll> data; // store root | (-size)
 
  UnionFind(ll sz) { data.assign(sz, -1); }
 
  bool unite(ll x, ll y) {
    x=find(x);
    y=find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x,y);
    data[x] += data[y]; // size
    data[y] = x; // root
    return true;
  }
 
  int find(int k) {
    if(data[k] < 0) return k;
    return data[k]=find(data[k]);
  }
 
  int size(int k) { return (-data[find(k)]); }
};


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
  ll n,m;
  cin>>n>>m;
  vector<ll> x(n+1),y(n+1),z(n+1);
  rep(i,n) cin>>x[i+1]>>y[i+1]>>z[i+1];

  vector< vector< vector<ll> > > \
   dp(n+1, vector< vector<ll> >(m+1, vector<ll>(3,0)));

  cout<<endl;

  for(ll i=1;i<=n;i++) {
    for(ll j=1;j<=m;j++) {
      ll p=abs(dp[i-1][j][0]);
      p+=abs(dp[i-1][j][1]);
      p+=abs(dp[i-1][j][2]);

      ///*
      ll q=abs(dp[i-1][j-1][0]+x[i]);
      q+=abs(dp[i-1][j-1][1]+y[i]);
      q+=abs(dp[i-1][j-1][2]+z[i]);
      //*/

      ll r=abs(dp[i][j-1][0]);
      r+=abs(dp[i][j-1][1]);
      r+=abs(dp[i][j-1][2]);

      if(max(p,max(q,r)) == p) {
        rep(k,3) dp[i][j][k]=dp[i-1][j][k];
      } else if(max(p,max(q,r)) == q) {
        dp[i][j][0]=dp[i-1][j-1][0]+x[i];
        dp[i][j][1]=dp[i-1][j-1][1]+y[i];
        dp[i][j][2]=dp[i-1][j-1][2]+z[i];
      } else if(max(p,max(q,r)) == r) {
        rep(k,3) dp[i][j][k]=dp[i][j-1][k];
      }

      /*
      if(p>q) rep(k,3) dp[i][j][k]=dp[i-1][j][k];
      else {
        dp[i][j][0]=dp[i-1][j-1][0]+x[i];
        dp[i][j][1]=dp[i-1][j-1][1]+y[i];
        dp[i][j][2]=dp[i-1][j-1][2]+z[i];
      }
      */

      printf("%lld %lld %lld, ", dp[i][j][0], dp[i][j][1], dp[i][j][2]);
    }

    cout<<endl;
  }

  printf("%lld\n", abs(dp[n][m][0])+abs(dp[n][m][1])+abs(dp[n][m][2]));

  /*
  for(ll i=1;i<=n;i++) {
    for(ll j=1;j<=m;j++) {
      dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+x[i]+y[i]+z[i]);
      cout<<dp[i][j]<<" ";
    }

    cout<<endl;
  }

  printf("%lld\n", dp[n][m]);
  */

  return 0;
}
