# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  lint l,r; cin >> l >> r;

  lint ans=2019;
  if(r-l>=2019) { ans = 0; }
  else {
    for(lint i=l;i<r;i++) {
      for(lint j=i+1;j<=r;j++) {
        ans = min(ans,(i*j)%2019);
      }
    }
  }

  cout << ans << endl;
  return 0;
}