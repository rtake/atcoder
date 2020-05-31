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


int main() {
  int x1,y1,x2,y2,x3,y3,r; cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

  x1+=100; x2+=100; x3+=100;
  y1+=100; y2+=100; y3+=100;
  vector<int> x(201,0), y(201,0);
  int red=0, blue=0;

  for(int i=x2;i<=x3;i++) { x[i]++; }
  for(int i=y2;i<=y3;i++) { y[i]++; }

  for(int i=0;i<=200;i++) {
    for(int j=0;j<=200;j++) {
      if((i-x1)*(i-x1) + (j-y1)*(j-y1) <= r*r) {
        if(x[i]+y[j] <= 1) { red=1; }
      } else {
        if(x[i]+y[j] >= 2) { blue=1; }
      }
    }
  }

  if(red == 1) { cout << "YES\n"; }
  else { cout << "NO\n"; }
  if(blue == 1) { cout << "YES\n"; }
  else { cout << "NO\n"; }
  return 0;
}
