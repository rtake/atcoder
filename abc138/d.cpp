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
  lint n,q; cin >> n >> q;
  vector< vector<lint> > m(n+1);
  vector<lint> s(n+1,0), t(n+1,0);

  for(int i=0;i<n-1;i++) {
    lint a,b; cin >> a >> b;
    m[a].push_back(b);
  }

  for(int i=0;i<q;i++) {
    lint p,x; cin >> p >> x;
    s[p] += x; 
  }  

  for(int i=1;i<=n;i++) {
    for(int j=0;j<(int)m[i].size();j++) {
      s[m[i][j]] += s[i];
    }
  }

  for(int i=1;i<=n;i++) { printf("%lld ",s[i]); }
  printf("\n");
  
  return 0;
}
