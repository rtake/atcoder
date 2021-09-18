# include <bits/stdc++.h>
// # include <atcoder/all>

typedef long long lint;
typedef long long ll;

using namespace std;
// using namespace atcoder;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)
#define ALL(a)  (a).begin(),(a).end()

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


// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }


int main() {
  int n,x,y;
  cin>>n>>x>>y;
  vector<int> a(n+1),b(n+1);
  rep(i,n) cin>>a[i+1]>>b[i+1];

  vector< vector< vector<int> > > \
   dp(x+400, vector< vector<int> >(y+400, vector<int>(n+1,1e9)));

/*
  dp[0][0][0]=0;
  for(int k=1;k<=n;k++) {
    dp[0][0][k]=0;

    for(int i=0;i<=x;i++) {
      for(int j=0;j<=y;j++) {
        // if(i-a[k] < 0) dp[i][j][k]=0;
        // if(j-b[k] < 0) dp[i][j][k]=0;

        if(i-a[k] >= 0 && j-b[k] >= 0) {
          // cout<<i<<" "<<a[k]<<" "<<j<<" "<<b[k]<<" ";
          dp[i][j][k]=min(dp[i-a[k]][j-b[k]][k-1]+1, dp[i][j][k-1]);
          // cout<<dp[i][j][k]<<endl;
        }
      }
    }


    for(int i=x-1;i>=0;i--) {
      for(int j=y-1;j>=0;j--) {
        dp[i][j][k]=min(dp[i][j+1][k],dp[i][j][k]);
      }
    }
    rep(i,x+1) {
      // rep(j,y+1) cout<<dp[i][j][k]<<" ";
      // cout<<endl;
    }
  }

*/

///*

  dp[0][0][0]=0;
  for(int k=1;k<=n;k++) {
    // dp[0][0][k]=0;

    for(int i=0;i<=x;i++) {
      for(int j=0;j<=y;j++) {
        dp[min(i+a[k],x)][min(j+b[k],y)][k]\
         =min(dp[i][j][k-1]+1,dp[min(i+a[k],x)][min(j+b[k],y)][k]);

        dp[i][j][k]=min(dp[i][j][k],dp[i][j][k-1]);
      }
    }

    rep(i,x) {
      // rep(j,y) cout<<dp[i][j][k]<<" ";
      // cout<<endl;
    }

    // cout<<endl;
  }
//*/

  if(dp[x][y][n] == 1e9) cout<<-1<<endl;
  else cout<<dp[x][y][n]<<endl;

  return 0;
}
