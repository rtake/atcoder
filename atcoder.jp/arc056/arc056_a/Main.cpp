# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  lint a,b,k,l; cin >> a >> b >> k >> l;

  lint ans=0, mod;
  ans = (k/l)*b + min( (k%l)*a, b );

  cout << ans << endl;
  return 0;
}