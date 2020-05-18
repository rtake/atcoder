# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int w,h,x,y; cin >> w >> h >> x >> y;  
  
  printf("%.10lf ",(double)w*(double)h/2);
  if(w%2==0 && h%2==0 && x==w/2 && y==h/2) { printf("1\n"); }
  else { printf("0\n"); }

  return 0;
}
