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
  lint l,x,y,s,d; cin >> l >> x >> y >> s >> d;

  if(y <= x) {
    printf("%.10lf\n",(double)((d+l-s)%l)/(double)(y+x));
  } else {
    // printf("%.10lf %.10lf\n",(double)((d+l-s)%l)/(double)(y+x),(double)((s+l-d)%l)/(double)(y-x));
    printf("%.10lf\n",min((double)((d+l-s)%l)/(double)(y+x),(double)((s+l-d)%l)/(double)(y-x)));
  }

  return 0;
}