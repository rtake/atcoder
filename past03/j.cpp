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
  lint n,m; cin >> n >> m;
  vector<lint> a(m); for(lint i=0;i<m;i++) { cin >> a[i]; }

  vector<lint> b(m,0),c(m,-1);
  b[0] = a[0]; // max value
  c[0] = 1; // who

  for(lint i=1;i<m;i++) {
    for(lint j=0;j<n;j++) {
      if(a[i] > b[j]) {
        b[j] = a[i];
        c[i] = j+1;
        break;
      } // for all children
    }
  } // for each sushi

  for(lint i=0;i<m;i++) { cout << c[i] << endl; }
  return 0;
}
