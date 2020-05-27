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
  lint a,b; cin >> a >> b;

  lint x = b/4-a/4, y = b/100-a/100, z = b/400-a/400;
  if(a%4 == 0) { x++; }
  if(a%100 == 0 && a>0) { y++; }
  if(a%400 == 0 && a>0) { z++; }
/*
  cout << x << endl;
  cout << y << endl;
  cout << z << endl;
*/
  cout << x-y+z << endl;
  return 0;
}