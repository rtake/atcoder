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
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];

  vector< vector<ll> > dp,sdp;
  dp=sdp=vector< vector<ll> >(n, vector<ll>(k+1,0));

  for(ll i=0;i<=a[0];i++) dp[0][i]=1;

  sdp[0][0]=dp[0][0];
  for(ll i=1;i<=k;i++) sdp[0][i]=sdp[0][i-1]+dp[0][i];

  // for(ll j=0;j<=k;j++) cout<<dp[0][j]<<" ";
  // cout<<endl;

  for(ll i=1;i<n;i++) {
    dp[i][0]=sdp[i-1][0];
    sdp[i][0]=dp[i][0];

    for(ll j=1;j<=k;j++) {
      if(j-a[i] >= 1) {
        dp[i][j]=(sdp[i-1][j]-sdp[i-1][j-a[i]-1]+mod)%mod;
      } else {
        dp[i][j]=sdp[i-1][j];
      }
 
      sdp[i][j]=(sdp[i][j-1]+dp[i][j])%mod;
    }

    // for(ll j=0;j<=k;j++) cout<<dp[i][j]<<" ";
    // cout<<endl;
  }

  cout<<dp[n-1][k]<<endl;

  return 0;
}
