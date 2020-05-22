# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint n; cin >> n;
  vector<lint> a(n),b(n); for(lint i=0;i<n;i++) { cin >> a[i] >> b[i]; }

  lint ans=0;
  for(lint i=n-1;i>=0;i--) {
    a[i] += ans;
    if(a[i]%b[i] != 0) { ans += (b[i] - a[i]%b[i]); }
  }

  cout << ans << endl;
  return 0;
}