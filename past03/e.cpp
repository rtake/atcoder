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


int main() {
  lint n,m,q; cin >> n >> m >> q;
  vector<lint> u(m), v(m); for(lint i=0;i<m;i++) { cin >> u[i] >> v[i]; }
  vector<lint> c(n); for(lint i=0;i<n;i++) { cin >> c[i]; }

  vector< vector<lint> > node(n);
  for(lint i=0;i<m;i++) {
    node[u[i]-1].push_back(v[i]-1);
    node[v[i]-1].push_back(u[i]-1);
  }

  for(lint i=0;i<q;i++) {
    lint a,x; cin >> a >> x;
    cout << c[x-1] << endl;

    if(a == 1) {
      for(lint j=0;j<(lint)node[x-1].size();j++) { c[node[x-1][j]] = c[x-1]; }
    } else {
      lint y; cin >> y;
      c[x-1] = y;
    }

  }

  return 0;
}
