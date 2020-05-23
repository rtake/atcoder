# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint n,a,b; cin >> n >> a >> b;

  lint ans;
  if((b-a)%2 == 1) {
    ans = min(a-1,n-b) + 1 + (b-a-1)/2;
  } else if((b-a)%2 == 0) {
    ans = (b-a)/2;
  }

  cout << ans << endl;
  return 0;
}