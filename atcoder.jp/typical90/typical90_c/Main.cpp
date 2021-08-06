# include <bits/stdc++.h>
//# include <atcoder/all>

typedef long long lint;

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

int main() {
  lint n; cin>>n;
  vector<lint> a(n-1),b(n-1); rep(i,n-1) cin>>a[i]>>b[i];

  vector< vector<lint> > G(n, vector<lint>(0));
  rep(i,n-1) {
    G[a[i]-1].push_back(b[i]-1);
    G[b[i]-1].push_back(a[i]-1);
  }

  vector<bool> is_arrived(n, false);
  vector<lint> arrived_node;
  vector<lint> distances(n, 0);
  deque<lint> dq;
  dq.push_back(0);
  is_arrived[0]=true;

  while(!dq.empty()) {
    lint cur=dq.front();
    arrived_node.push_back(cur);
    dq.pop_front();

    for(auto node:G[cur]) {
      if(!is_arrived[node]) {
        is_arrived[node]=true;
        dq.push_back(node);
      }
    }
  }

  lint start_node=arrived_node[n-1];
  dq=deque<lint>(0);
  is_arrived=vector<bool>(n,false);
  arrived_node=vector<lint>(0);

  dq.push_back(start_node);
  is_arrived[start_node]=true;

  while(!dq.empty()) {
    lint cur=dq.front();
    arrived_node.push_back(cur);
    dq.pop_front();

    for(auto node:G[cur]) {
      if(!is_arrived[node]) {
        is_arrived[node]=true;
        dq.push_back(node);
        distances[node]=distances[cur]+1;
      }
    }
  }

  lint end=arrived_node[n-1];
  printf("%lld\n", distances[end]+1);

  return 0;
}