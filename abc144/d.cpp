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
  double a,b,x; cin >> a >> b >> x;

  double angle, pi=acos(-1);
  if(x > a*a*b/2) { angle = atan(2*b/a-2*x/(a*a*a))*180/pi;  }
  else { angle = atan(a*b*b/(2*x))*180/pi; }

  printf("%.10lf\n",angle);
  return 0;
}
