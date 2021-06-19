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


lint power(lint x, lint n) {
  lint ret=x;
  for(lint i=1;i<n;i++) {
    ret = (ret*x) %1000000007;
  }
  return ret;
}


int main() {
  int n;
  scanf("%d", &n);

  lint ans=power(10,n)-(2*power(9,n) - power(8,n));
  ans %= 1000000007;
  // ans = (ans+1000000007)%1000000007;
  printf("%lld\n", ans);
  return 0;
}
