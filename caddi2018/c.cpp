# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  lint n,p; cin >> n >> p;

  if(n==1) {
    cout << p << endl;
    return 0;
  }

  lint ans=1, p_sqrt=sqrt(p);
  vector<lint> c(p_sqrt,0);

  for(lint i=2;i<=p_sqrt;i++) {
    while(p > 1) {
      if(p%i == 0) {
        p /= i;
        c[i]++;
      } else { break; }
    }
  }

  for(lint i=2;i<=p_sqrt;i++) {
    if(c[i]/n >= 1) { ans *= pow(i, (c[i]/n) ); }
  }

  cout << ans << endl;
  return 0;
}
