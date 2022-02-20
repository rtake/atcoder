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


int main() {
  int h,w;
  cin>>h>>w;
  vector<int> c(2),d(2);
  cin>>c[0]>>c[1]>>d[0]>>d[1];
  c[0]--;
  c[1]--;
  d[0]--;
  d[1]--;

  vector<string> s(h);
  rep(i,h) cin>>s[i];

  int inf=1e9;
  vector< vector<int> > m(h, vector<int>(w,inf));
  vector< vector<bool> > is_checked(h, vector<bool>(w,false));

  deque<int> dq;
  m[c[0]][c[1]]=0;
  dq.push_back(c[0]*w+c[1]);

  while(!dq.empty()) {
    int cur=dq.front();
    dq.pop_front();

    for(int i=-2;i<=2;i++) {
      if(cur/w+i < 0 || cur/w+i >= h) continue;

      for(int j=-2;j<=2;j++) {
        if(cur%w+j < 0 || cur%w+j >= w) continue;
        if(is_checked[cur/w+i][cur%w+j]) continue;
        if(s[cur/w+i][cur%w+j] == '#') continue;

        is_checked[cur/w+i][cur%w+j]=true;
        m[cur/w+i][cur%w+j]=min(m[cur/w+i][cur%w+j],m[cur/w][cur%w]+1);
        dq.push_back((cur/w+i)*w+cur%w+j);
      }
    }
  }

  UnionFind uf(h*w);

  rep(i,h) rep(j,w) {
    if(s[i][j] == '#') continue;

    for(int k=-1;k<=1;k++) {
      if(i+k<0 || i+k>=h) continue;
      if(s[i+k][j] == '#') continue;
      uf.unite(i*w+j,(i+k)*w+j);
    }

    for(int k=-1;k<=1;k++) {
      if(j+k<0 || j+k>=w) continue;
      if(s[i][j+k] == '#') continue;
      uf.unite(i*w+j,i*w+j+k);
    }
  }

  int ans=h*w;
  rep(i,h*w) {
    if(uf.find(i) == uf.find(d[0]*w+d[1])) {
      // cout<<uf.find(i)<<" "<<uf.find(d[0]*w+d[1])<<endl;
      ans=min(ans,m[i/w][i%w]);
    }
  }

  if(m[d[0]][d[1]] == inf) cout<<-1<<endl;
  else cout<<ans<<endl;

  return 0;
}
