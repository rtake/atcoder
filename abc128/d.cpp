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
  int n,k;
  cin>>n>>k;
  vector<ll> v(n);
  rep(i,n) cin>>v[i];

  vector<ll> f(k+1,0);
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  
  for(ll i=1,l=0;i<=k && l<n;i++) {
    f[i]=f[i-1];

    if(pq.empty()) {
      if(v[l] < 0) pq.push(v[l]);

      f[i]+=v[l];
      l++;
    } else {
      ll top=pq.top();

      if(v[l] > abs(top)) {
        f[i]+=v[l];
        l++;
      } else {
        f[i]+=abs(top);
        pq.pop();
      }
    }
  }

  // for(ll i=1;i<=k;i++) f[i]=max(f[i],f[i-1]);
  for(ll i=1;i<=k;i++) cout<<f[i]<<" "; cout<<endl;

/*
  for(ll i=1;i<=k;i++) cout<<f[i]<<" ";
  cout<<endl;
*/

  reverse(v.begin(), v.end());

  vector<ll> b(k+1,0);
  pq=priority_queue<ll, vector<ll>, greater<ll>>();

  for(ll i=1,l=0;i<=k && l<n;i++) {
    b[i]=b[i-1];

    if(pq.empty()) {
      if(v[l] < 0) pq.push(v[l]);

      b[i]+=v[l];
      l++;
    } else {
      ll top=pq.top();

      if(v[l] > abs(top)) {
        b[i]+=v[l];
        l++;
      } else {
        b[i]+=abs(top);
        pq.pop();
      }
    }
  }

  // for(ll i=1;i<=k;i++) b[i]=max(b[i],b[i-1]);
  for(ll i=1;i<=k;i++) cout<<b[i]<<" "; cout<<endl;
  

  ll ans=0;
  for(ll i=0;i<=k;i++) ans=max(ans,f[i]+b[k-i]);

  cout<<ans<<endl;

  return 0;
}
