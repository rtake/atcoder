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
  lint q,h,s,d,n; cin >> q >> h >> s >> d >> n;
  
  lint num, ans=0;
  num = n/2; // number of 2L
  ans += min(num*d,min(num*(2*s),min(num*(4*h),num*(8*q))));
  n -= num*2;

  num = n;
  ans += min(num*s,min(num*(2*h),num*(num*(4*q))));

  cout << ans << endl;
  return 0;
}
