# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int w,h,n; cin >> w >> h >> n;
  vector<int> x(n),y(n),a(n); for(int i=0;i<n;i++) { cin >> x[i] >> y[i] >> a[i]; }

  int xmin=0, xmax=w, ymin=0, ymax=h;
  for(int i=0;i<n;i++) {
    if(a[i] == 1) { xmin = max(xmin,x[i]); }
    else if(a[i] == 2) { xmax = min(xmax,x[i]); }
    else if(a[i] == 3) { ymin = max(ymin,y[i]); }
    else if(a[i] == 4) { ymax = min(ymax,y[i]); }
  }

  if(xmin >= xmax || ymin >= ymax) { cout << 0 << endl; }
  else { cout << (xmax-xmin)*(ymax-ymin) << endl; }
  return 0;
}