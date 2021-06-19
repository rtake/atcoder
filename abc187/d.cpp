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
  lint n, num=0;
  scanf("%lld", &n);
  vector<lint> a(n,0), b(n,0), c(n,0);
  for(lint i=0;i<n;i++) { 
    scanf("%lld %lld", &a[i], &b[i]);
    num -= a[i];
  }
  
  for(lint i=0;i<n;i++) { c[i] = 2*a[i] + b[i]; }
  sort(c.begin(), c.end(), greater<lint>());

  for(lint i=0;i<n;i++) {
    num += c[i];
    if(num > 0) {
      printf("%lld\n", i+1);
      break;
    }
  }

  return 0;
}
