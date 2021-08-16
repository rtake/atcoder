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

int main() {
  ll h,w,rs,cs,rt,ct;
  cin>>h>>w>>rs>>cs>>rt>>ct;
  char s[h][w];
  rep(i,h) cin>>s[i];

  ll c,r,cur;
  vector<ll> t(h*w,9999999);
  vector<bool> is_arrived(h*w,false);
  deque<ll> dq;

  rs--;
  cs--;
  rt--;
  ct--;

  dq.push_back(rs*w+cs);
  t[rs*w+cs]=-1;
  is_arrived[rs*w+cs]=true;

  while(!dq.empty()) {
    cur=dq.front();
    if(cur == rt*w+ct) break;

    dq.pop_front();
    is_arrived[cur]=true;
    r=cur/w;
    c=cur%w;

    if(r-1>=0 && s[r-1][c]=='.' && !is_arrived[(r-1)*w+c]) {
      dq.push_back((r-1)*w+c);
      t[(r-1)*w+c]=cur;
    }

    if(r+1<h && s[r+1][c]=='.' && !is_arrived[(r+1)*w+c]) {
      dq.push_back((r+1)*w+c);
      t[(r+1)*w+c]=cur;
    }

    if(c-1>=0 && s[r][c-1]=='.' && !is_arrived[r*w+c-1]) {
      dq.push_back(r*w+c-1);
      t[r*w+c-1]=cur;
    }

    if(c+1<w && s[r][c+1]=='.' && !is_arrived[r*w+c+1]) {
      dq.push_back(r*w+c+1);
      t[r*w+c+1]=cur;
    }

  }

  ll ans=0;
  while(true) {
    // cout<<cur<<endl;

    ll prev=t[cur];
    if(prev == -1) break;

    ll pprev=t[prev];
    if(pprev == -1) break;
    
    if((pprev-prev)%w == 0 && (prev-cur)%w == 0) {}
    else if(abs(pprev-prev) == 1 && abs(prev-cur) == 1) {}
    else ans++;

    cur=prev;
  }

  printf("%lld\n", ans);

  return 0;
}
