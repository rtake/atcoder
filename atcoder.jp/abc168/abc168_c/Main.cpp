# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  double a,b,h,m; cin >> a >> b >> h >> m;
  double xa,ya,xb,yb,angle_a,angle_b,pi=acos(-1);

  angle_b = (360/60)*m;
  angle_a = (360/12)*h + 360*m/(60*12); // cout << angle_a << endl;

  xa = a*cos(angle_a*pi/180); //cout << xa << endl;
  ya = a*sin(angle_a*pi/180); //cout << ya << endl;
  xb = b*cos(angle_b*pi/180); //cout << xb << endl;
  yb = b*sin(angle_b*pi/180); //cout << yb << endl;

  printf("%.20lf\n", sqrt( (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) ) );
  return 0;
}