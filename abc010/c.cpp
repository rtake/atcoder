# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  double txa,tya,txb,tyb,t,v,n; cin >> txa >> tya >> txb >> tyb >> t >> v >> n;
  vector<double> x(n,0),y(n,0); for(int i=0;i<n;i++) { cin >> x[i] >> y[i]; }

  for(int i=0;i<n;i++) {
    if(t*v >= sqrt((x[i]-txa)*(x[i]-txa) + (y[i]-tya)*(y[i]-tya)) + sqrt((x[i]-txb)*(x[i]-txb) + (y[i]-tyb)*(y[i]-tyb)) ) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}
