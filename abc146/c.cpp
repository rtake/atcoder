# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

lint C(lint n, lint k) {
  if(n == k) { return 1; }
  else if(n < k) { return 0; }
  else if(k == 0) { return 1; }
  else if(k == 1) { return n; }
  else return C(n-1,k-1) + C(n-1,k);
}

lint P(lint n, lint k) {
  if(k == 1) { return n; }
  return (n*(P(n-1,k-1)%1000000007)%1000000007);
}


int main() {
  lint a,b,x; cin >> a >> b >> x;

  for(int d=9;d>=1;d--) {
    lint n=(x-b*d)/a;

    if(pow(10,d-1) <= n && n < pow(10,d)) {
      cout << min(n,1000000000LL) << endl ;
      return 0;
    }
  }

  cout << 0 << endl;
  return 0;
}
