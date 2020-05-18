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
  vector<lint> x(n); for(int i=0;i<n;i++) { cin >> x[i]; }

  vector<lint> y=x;
  sort(y.begin(),y.end());
  lint med0=y[n/2-1], med1=y[n/2];

  for(int i=0;i<n;i++) {
    if(x[i]>med0) { cout << med0 << endl; }
    else { cout << med1 << endl; }
  }

  return 0;
}