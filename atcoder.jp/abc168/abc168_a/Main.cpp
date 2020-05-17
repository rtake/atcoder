# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n; cin >> n;
  if(n%10==3) { cout << "bon\n"; }
  else if(n%10==0 || n%10==1 || n%10==6 || n%10==8) { cout << "pon\n"; }
  else { cout << "hon\n"; }

  return 0;
}