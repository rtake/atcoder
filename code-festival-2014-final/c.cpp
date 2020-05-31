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


lint f(lint n) {
  lint ret=0, n0=n, t=0;

  while(n > 0) {
    ret += (n%10)*pow(n0,t);
    n /= 10;
    t++;
  }

  return ret;
}


int main() {
  lint a; cin >> a;

  lint k;
  for(k=10;k<=10000;k++) {
    //cout << f(k) << endl;
    if(f(k) == a) { break; }
  }

  if(k > 10000) { cout << "-1\n"; }
  else { cout << k << endl; }
  return 0;
}
