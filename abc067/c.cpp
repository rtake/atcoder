# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n; cin >> n;
  vector<lint> a(n); for(int i =0;i<n;i++) { cin >> a[i]; }

  lint ans;
  vector<lint> b(n);
  b[0] = a[0];
  for(int i =1;i<n;i++) { b[i] = b[i-1]+a[i]; }

  ans=2000000000;
  for(int i=0;i<n-1;i++) { ans = min( ans, abs( (b[n-1]-b[i])-b[i] ) ); }

  cout << ans << endl;
  return 0;
}
