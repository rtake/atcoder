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
  vector<int> s(n),t(m);
  rep(i,n) cin>>s[i];
  rep(i,m) cin>>t[i];

  vector<int> one,zero;
  rep(i,n) {
    if(s[i] == 1) one.push_back(i);
    else zero.push_back(i);
  }

  ll inf=999999999;
  vector<int> a(n,0),l(n,inf),r(n,inf);
  for(ll i=n-1;i>=0;i--) {
    if(s[i] != s[(i+1)%n]) r[i]=1;
    else r[i]=r[i+1]+1;
  }

  rep(i,n) {
    if(s[i] != s[(i-1+n)%n]) l[i]=1;
    else l[i]=l[(i-1+n)%n]+1;
  }

  rep(i,n) cout<<l[i]<<" "<<r[i]<<endl;

  ll cur=0,prev=0,ans=0;
  rep(i,m) {
    if(t[i] == s[cur]) ans++;
    else {
      if(l[cur]<r[cur]) {
        ans+=l[cur];
        ans++;
        cur=(cur-l[cur]+n)%n;
      } else {
        ans+=r[cur];
        ans++;
        cur=(cur+r[cur]+n)%n;
      }
    }
  }

  cout<<ans<<endl;

  /*
  vector<int> a(n);
  rep(i,n) {
    if(s[i] == 0) {
      auto pos=lower_bound(one.begin(), one.end(), i);
      int index=pos-one.begin();
      a[i]=min(abs(one[index-1]-i),abs(i-one[index]));

      cout<<i<<" "<<index<<" "<<one[index]<<" "<<one[index-1]<<endl;
      cout<<i-one[index-1]<<" "<<one[index]-i<<endl;
    } else {
      auto pos=lower_bound(zero.begin(), zero.end(), i);
      int index=pos-zero.begin();
      a[i]=min(abs(zero[index-1]-i),abs(i-zero[index]));

      // cout<<i<<" "<<index<<" "<<zero[index]<<endl;
      // cout<<i-zero[index-1]<<" "<<zero[index]-i<<endl;
    }
  }
  
  cout<<endl;
  rep(i,n) cout<<a[i]<<endl;
  */

  return 0;
}