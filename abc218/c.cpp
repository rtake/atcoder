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


// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }

bool trans(vector< pair<int,int> > sv, vector< pair<int,int> > tv) {
  int cnt=sv.size();
  sort(ALL(sv));
  sort(ALL(tv));

  int x=sv[0].first-tv[0].first;
  int y=sv[0].second-tv[0].second;

  for(int i=1;i<cnt;i++) {
    if(x != sv[i].first-tv[i].first || y != sv[i].second-tv[i].second) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;
  cin>>n;
  vector<string> s(n),t(n);
  rep(i,n) cin>>s[i];
  rep(i,n) cin>>t[i];

  int scnt=0,tcnt=0;
  vector< pair<int,int> > sv,tv;
  rep(i,n) rep(j,n) {
    if(s[i][j] == '#') {
      sv.emplace_back(i,j);
      scnt++;
    }
  }

  rep(i,n) rep(j,n) {
    if(t[i][j] == '#') {
      tv.emplace_back(i,j);
      tcnt++;
    }
  }

  if(scnt != tcnt) {
    cout<<"No"<<endl;
    return 0;
  }

  if(trans(sv,tv)) {
    cout<<"Yes"<<endl;
    return 0;
  }

  vector<string> s0=s, s1=s, s2=s;
  vector< pair<int,int> > sv0,sv1,sv2;

  rep(i,n) rep(j,n) s0[j][n-1-i]=s[i][j]; // pi/2
  rep(i,n) rep(j,n) if(s0[i][j] == '#') sv0.emplace_back(i,j);

  if(trans(sv0,tv)) {
    cout<<"Yes"<<endl;
    return 0;
  }


  rep(i,n) rep(j,n) s1[j][n-1-i]=s0[i][j]; // pi
  rep(i,n) rep(j,n) if(s1[i][j] == '#') sv1.emplace_back(i,j);
  if(trans(sv1,tv)) {
    cout<<"Yes"<<endl;
    return 0;
  }

  rep(i,n) rep(j,n) s2[j][n-1-i]=s1[i][j]; // pi*3/2
  rep(i,n) rep(j,n) if(s2[i][j] == '#') sv2.emplace_back(i,j);
  if(trans(sv2,tv)) {
    cout<<"Yes"<<endl;
    return 0;
  }

  cout<<"No"<<endl;

  return 0;
}