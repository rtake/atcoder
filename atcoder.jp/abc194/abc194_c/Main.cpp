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
  vector<lint> a(n); for(lint i=0;i<n;i++) cin >> a[i];

  vector<lint> b(n), c(n);
  b[0] = a[0];
  c[0] = a[0]*a[0];
  for(lint i=1;i<n;i++) {
    b[i] = b[i-1] + a[i];
    c[i] = c[i-1] + a[i]*a[i];
  }

  lint ans=0;
  for(lint i=1;i<n;i++) ans += i*a[i]*a[i] - 2*a[i]*b[i-1] + c[i-1];
  printf("%lld\n", ans);

  return 0;
}