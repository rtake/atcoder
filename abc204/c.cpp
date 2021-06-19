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


vector<int> check;

void dfs(vector< vector<int> > tree, int cur) {
  check[cur] = 1;
  for(auto x : tree[cur]) {
    if(check[x] == 0) { dfs(tree, x); }
  }
}


int main() {
  int n,m;
  scanf("%d %d\n", &n, &m);
  int a[m], b[m];
  for(int i=0;i<m;i++) { scanf("%d %d\n", &a[i], &b[i]); }

  lint ans=0;
  vector< vector<int> > route(n+1, vector<int>(0));
  for(int i=0;i<m;i++) { route[a[i]].push_back(b[i]); }

  for(int j=1;j<=n;j++) {
    check = vector<int>(n+1,0);
    dfs(route, j);
    for(int k=1;k<=n;k++) { ans += check[k]; }
    // ans--; // self
  }

  printf("%lld\n", ans);

  return 0;
}
