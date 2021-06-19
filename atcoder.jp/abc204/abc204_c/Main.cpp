# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

lint C(lint n, lint k) {
  if(n == k) { return 1; }
  else if(n < k) { return 0; }
  else if(k == 0) { return 1; }
  else if(k == 1) { return n; }
  else return C(n-1,k-1) + C(n-1,k);
}

lint P(lint n, lint k) {
  if(k == 1) { return n; }
  return (n*(P(n-1,k-1)%1000000007)%1000000007);
}


vector< vector<int> > G;
vector<int> check;

void dfs(int cur) {
  check[cur] = 1;
  for(auto x : G[cur]) {
    if(check[x] == 0) { dfs(x); }
  }
}


int main() {
  int n,m;
  scanf("%d %d\n", &n, &m);
  int a[m], b[m];
  for(int i=0;i<m;i++) { scanf("%d %d\n", &a[i], &b[i]); }

  lint ans=0;
  G.resize(n+1);
  for(int i=0;i<m;i++) { G[a[i]].push_back(b[i]); }

  for(int j=1;j<=n;j++) {
    check = vector<int>(n+1,0);
    dfs(j);
    for(int k=1;k<=n;k++) { ans += check[k]; }
    // ans--; // self
  }

  printf("%lld\n", ans);

  return 0;
}