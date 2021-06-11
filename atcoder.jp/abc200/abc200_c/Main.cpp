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
  vector<lint> a(n,0); for(lint i=0;i<n;i++) { cin >> a[i]; }

  lint ans=0;
  vector<lint> b(200,0);
  for(lint i=0;i<n;i++) { b[a[i]%200]++; }
  for(lint i=0;i<200;i++) {
    if(b[i] > 1) {
      // ans += P(b[i], 2)/2;
      ans += b[i]*(b[i]-1)/2;
    }
  }

  printf("%lld\n", ans);
  return 0;
}