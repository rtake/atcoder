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

vector< vector<ll> > G;
vector<ll> dp;

void dfs(ll pos, ll pre) {
  dp[pos]=1;
  for(int i:G[pos]) {
    if(i != pre) {
      dfs(i,pos);
      dp[pos]+=dp[i];
    }
  }
}


int main() {
  ll n;
  cin>>n;
  vector<ll> u(n-1),v(n-1);
  rep(i,n-1) cin>>u[i]>>v[i];

  rep(i,n-1) { u[i]--; v[i]--; }

  G=vector< vector<ll> >(n);
  dp=vector<ll>(n,0);

  rep(i,n-1) {
    G[u[i]].push_back(v[i]);
    G[v[i]].push_back(u[i]);
  }

  dfs(0,-1);

  // rep(i,n) dp[i]--;

  // rep(i,n) cout<<dp[i]<<" ";
  // cout<<endl;

  vector<ll> ans(n,0);
  rep(i,n-1) {
    ll d=abs(dp[u[i]]-dp[v[i]]);

    if(dp[u[i]] > dp[v[i]]) {
      ans[u[i]]+=(d)*(dp[v[i]]);
      ans[v[i]]+=d*dp[v[i]];
    } else {
      ans[u[i]]+=(d)*(dp[u[i]]);
      ans[v[i]]+=d*dp[u[i]];
    }

    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
  }

  // rep(i,n) cout<<ans[i]<<endl;

  return 0;
}
