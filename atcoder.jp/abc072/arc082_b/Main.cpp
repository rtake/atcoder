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
  vector<lint> p(n+1); for(lint i=1;i<n+1;i++) { cin >> p[i]; }

  lint ans=0;

  for(lint i=1;i<n+1;i++) {
    if(i==p[i]) {
      if(i<n) {
        p[i]=p[i+1];
        p[i+1]=i;
      } else if(i==n) {
        p[n]=p[n-1];
        p[n-1]=n;
      }
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}