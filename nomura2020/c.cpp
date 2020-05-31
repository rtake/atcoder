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
  vector<lint> a(n+1); for(lint i=0;i<=n;i++) { cin >> a[i]; }

  vector<lint> b(n+1), c(n+1);
  b[n] = a[n];
  c[0] = 1LL;

  for(lint i=n-1;i>=0;i--) { b[i] = b[i+1]+a[i]; } // b
  for(lint i=1;i<=n;i++) { c[i] = min((c[i-1]-a[i-1])*2,(lint)1000000000000000); } // max leaf

  lint ans=0LL;
  for(lint i=0;i<=n;i++) {
    if(a[i] > c[i]) {
      cout << "-1\n";
      return 0;
    }

    ans += min(lint(b[i]),lint(c[i]));
  } // ans

  cout << ans << endl;
  return 0;
}
