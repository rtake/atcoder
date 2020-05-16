# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  lint n,k; cin >> n >> k;
  vector<lint> a(n,0);
  lint index;

  for(lint i=0;i<n;i++) {
    cin >> a[i];
    if(a[i] == 1) { index = i; }
  }

  lint ans=0;
  ans = (n-1)/(k-1);
  if( (n-1)%(k-1) > 0 ) { ans += 1; }

  cout << ans << endl;
  return 0;
}