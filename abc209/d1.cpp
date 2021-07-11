# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

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
  lint n,q; cin>>n>>q;
  vector<lint> a(n),b(n),c(q),d(q);
  for(lint i=0;i<n-1;i++) cin>>a[i]>>b[i];
  for(lint i=0;i<q;i++) cin>>c[i]>>d[i];

  vector< vector<lint> > G(n, vector<lint>(0));
  for(lint i=0;i<n-1;i++) {
    G[a[i]-1].push_back(b[i]-1);
    G[b[i]-1].push_back(a[i]-1);
  }

  vector<int> e(n,-1);
  deque<lint> dq;

  e[0]=0;
  dq.push_back(0);

  while(!dq.empty()) {
    lint cur=dq.front(); dq.pop_front();

    for(auto x:G[cur]) {
      if(e[x] < 0) {
        e[x] = (e[cur]+1)%2;
        dq.push_back(x);
      }
    }
  }


  for(lint i=0;i<q;i++) {
    c[i]--; d[i]--;
    if(e[c[i]] != e[d[i]]) cout << "Road\n";
    else cout << "Town\n";
  }

  return 0;
}
