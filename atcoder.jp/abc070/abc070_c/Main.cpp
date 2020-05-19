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
  vector<lint> t(n); for(lint i=0;i<n;i++) { cin >> t[i]; }

  lint ans=t[0];
  for(lint i=1;i<n;i++) {
    ans = (lint)lcm(ans,t[i]);
  }

  cout << ans << endl;
  return 0;
}