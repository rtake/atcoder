# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%1000000007;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
}


int main() {
  lint inf=999999999, mod=1000000007, n,m; cin>>n>>m;

  vector< vector<lint> > G(n, vector<lint>(0));
  rep(i,m) {
    lint a,b; cin>>a>>b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }

  vector<lint> distances(n, inf), counts(n,0);
  distances[0]=0;
  counts[0]=1;

  deque<lint> dq;
  dq.push_back(0);

  lint cur, prev=-1;

  while(!dq.empty()) {
    // cout<<cur<<endl;
    cur=dq.front();
    dq.pop_front();

    for(auto node:G[cur]) {
      if(distances[node] == inf) {
        // arrived for the first time
        dq.push_back(node);
        distances[node] = distances[cur]+1;
        counts[node] = (counts[node]+counts[cur])%mod;
      } else if(distances[node] == distances[cur]+1) {
        counts[node] = (counts[node]+counts[cur])%mod;
      }
    }
  }

  printf("%lld\n", counts[n-1]);
  return 0;
}