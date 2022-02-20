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
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  rep(i,h) cin>>a[i];

  int s_pos,g_pos;
  rep(i,h) rep(j,w) {
    if(a[i][j] == 'S') s_pos=i*w+j;
    else if(a[i][j] == 'G') g_pos=i*w+j;
  }

  vector< vector<int> > d(h, vector<int>(w,1e9));
  vector<int> s(26,1e9),g(26,1e9);

  deque<int> dq;

  // start
  dq.push_back(s_pos);
  d[s_pos/w][s_pos%w]=0;

  while(!dq.empty()) {
    int cur=dq.front();
    dq.pop_front();

    int r=cur/w, c=cur%w;

    if(c-1 >= 0) {
      if(d[r][c-1] == 1e9) {
        if(a[r][c-1] == '#') {}
        else if(a[r][c-1] == '.') {
          d[r][c-1]=d[r][c]+1;
          dq.push_back(r*w+c-1);
        } else {
          s[a[r][c-1]-'a']=min(s[a[r][c-1]-'a'],d[r][c]+1);
          dq.push_back(r*w+c-1);
        }
      }
    } 

    if(c+1 < w) {
      if(d[r][c+1] == 1e9) {
        if(a[r][c+1] == '#') {}
        else if(a[r][c+1] == '.') {
          d[r][c+1]=d[r][c]+1;
          dq.push_back(r*w+c+1);
        } else {
          s[a[r][c+1]-'a']=min(s[a[r][c+1]-'a'],d[r][c]+1);
          dq.push_back(r*w+c+1);
        }
      }
    } 

    if(r-1 >= 0) {
      if(d[r-1][c] == 1e9) {
        if(a[r-1][c] == '#') {}
        else if(a[r-1][c] == '.') {
          d[r-1][c]=d[r][c]+1;
          dq.push_back((r-1)*w+c);
        } else {
          s[a[r-1][c]-'a']=min(s[a[r-1][c]-'a'],d[r][c]+1);
          dq.push_back((r-1)*w+c);
        }
      }
    } 

    if(r+1 < h) {
      if(d[r+1][c] == 1e9) {
        if(a[r+1][c] == '#') {}
        else if(a[r+1][c] == '.') {
          d[r+1][c]=d[r][c]+1;
          dq.push_back((r+1)*w+c);
        } else {
          s[a[r+1][c]-'a']=min(s[a[r+1][c]-'a'],d[r][c]+1);
          dq.push_back((r+1)*w+c);
        }
      }
    } 

    cout<<cur<<endl;
  }

  int ans=d[s_pos/w][s_pos%w];

  for(int i=0;i<26;i++) {
    cout<<s[i]<<" "<<g[i]<<endl;
    ans=min(ans,s[i]+g[i]);
  }

  if(ans == 1e9) ans=-1;
  cout<<ans<<endl;

  return 0;
}
