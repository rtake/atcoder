# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  lint n; cin >> n;
  vector<lint> a(n,0),b(n,0),c(n,0); for(lint i=0;i<n;i++) { cin >> a[i]; }

  for(lint i=0;i<n;i++) {
    while(true) {
      if(a[i] %2 == 0) {
        a[i] /= 2;
        b[i]++;
      } else if(a[i] %2 == 1) {
        break;
      }
    }
  } // for each elem.

  sort(b.begin(),b.end());
  for(lint i=0;i<n;i++) {
    if(i%2 == 0) { c[i] = b[i/2]; }
    else if(i%2 == 1) { c[i] = b[(n-1)-(i/2)]; }
  }

  for(lint i=0;i<n-1;i++) {
    if(c[i]+c[i+1] < 2) { cout << "No\n"; return 0; }
  }

  cout << "Yes\n";
  return 0;
}