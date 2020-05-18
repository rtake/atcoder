# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n,x; cin >> n >> x;
  vector<int> a(n,0); for(int i=0;i<n;i++) { cin >> a[i]; }

  int sum=0;
  for(int i=0;i<n;i++) {
    if(x & 1<<i) { sum += a[i]; }
  }

  cout << sum << endl;
  return 0;
}
