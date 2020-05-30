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
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  lint sum=0;
  for(lint i=0;i<n;i++) { sum += a[i]; }

  lint ans=0;
  if(sum%n == 0) {
    for(lint i=0;i<n;i++) { ans += (a[i]-sum/n)*(a[i]-sum/n); }
  } else {
    lint ans0=0,ans1=0;
    for(lint i=0;i<n;i++) { ans0 += (a[i]-sum/n)*(a[i]-sum/n); }
    for(lint i=0;i<n;i++) { ans1 += (a[i]-sum/n-1)*(a[i]-sum/n-1); }
    ans = min(ans0,ans1);
  }

  cout << ans << endl;
  return 0;
}
