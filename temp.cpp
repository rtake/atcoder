# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int gcd(int x, int y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

int lcm(int x, int y) { return abs(x,y)/gcd(x,y); }


int main() {





  return 0;
}
