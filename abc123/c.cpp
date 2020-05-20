# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  lint n,a,b,c,d,e; cin >> n >> a >> b >> c >> d >> e;

  lint ans=5, m=min(a,min(b,min(c,min(d,e))));

  if(n>m) {
    ans += (n/m-1);
    if(n%m > 0) { ans++; }
  }

  cout << ans << endl;
  return 0;
}
