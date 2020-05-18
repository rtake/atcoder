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
  vector<lint> k(n-1,0); for(int i=0;i<n-1;i++) { cin >> k[i]; }

  vector<lint> l(n,0);
  l[0] = k[0];
  for(int i=1;i<n-1;i++) { l[i] = min(k[i-1],k[i]); }
  l[n-1] = k[n-2];

  for(int i=0;i<n;i++) { cout << l[i] << " "; }
  cout << endl;
  return 0;
}
