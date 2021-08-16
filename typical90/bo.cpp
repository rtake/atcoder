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

/*
ll convert_8_to_9(ll n) {
  stringstream ss8;
  ss8<<n;
  string s=ss8.str();

  ll sum=0, cur=1;
  for(ll i=s.length()-1;i>=0;i--) {
    sum+=(s[i]-'0')*cur;
    cur*=8;
  }

  cur=1;
  while(cur<=sum) {
    if(cur*9>sum) break;
    cur*=9;
  }

  string s9;
  while(cur>=1) {
    s9.push_back(sum/cur+'0');
    sum%=cur;
    cur/=9;
  }

  for(ll i=0;i<s9.length();i++) {
    if(s9[i] == '8') s9[i]='5';
  }

  // cout<<s9<<endl;
  return stol(s9);
}
*/

ll base8_to_ll(string s) {
  ll ans=0, cur=1;
  for(int i=s.length()-1;i>=0;i--) {
    ans+=(s[i]-'0')*cur;
    cur*=8;
  }
  return ans;
}

string long_to_base9(ll n) {
  string ans;

  while(n>0) {
    char c=n%9+'0';
    if(c == '8') c='5';

    ans=c+ans;
    n/=9;
  }

  return ans;
}

int main() {
  string s;
  cin>>s;
  ll k;
  cin>>k;

  if(s == "0") {
    cout<<s<<endl;
    return 0;
  }

  rep(i,k) {
    ll n=base8_to_ll(s);
    s=long_to_base9(n);
  }

  cout<<s<<endl;

  return 0;
}
