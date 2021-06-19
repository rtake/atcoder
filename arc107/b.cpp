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
  lint n,k;
  scanf("%lld %lld\n", &n, &k);

  int cmb[2*n+1]; // number of combination
  for(int i=2;i<=2*n;i++) {
    
  }

  lint ans=0;

  // (a+b) - (c+d) = k
  for(lint i=2;i<=2*n;i++) {
    // a+d
    // (a+b) - (c+d) = k
    // (c+d) = (a+b) - k

    if(i-k < 2 || i-k > 2*n) { continue; }
    ans += cmb[i]*cmb[i-k];
  }

  printf("%d\n", ans);
  return 0;
}
