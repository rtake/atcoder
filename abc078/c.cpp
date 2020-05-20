# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n,m; cin >> n >> m;
  int ans=pow(2,m)*(1900*m+100*(n-m));
  cout << ans << endl;
  return 0;
}
