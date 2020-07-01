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
  lint n; cin >> n;
  vector<lint> t(n+1,0),x(n+1,0),y(n+1,0); for(lint i=1;i<=n;i++) { cin >> t[i] >> x[i] >> y[i]; }

  for(lint i=1;i<=n;i++) {
    lint diff = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
    if(diff>t[i]-t[i-1]) {
      printf("No\n");
      return 0;
    } else {
      if(diff%2 != (t[i]-t[i-1])%2) {
        printf("No\n");
        return 0;
      }
    }
  }

  printf("Yes\n");
  return 0;
}
