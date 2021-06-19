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
  lint n, s=1;
  scanf("%lld\n", &n);
  char t[n];
  scanf("%s", t);

  for(int i=0;i<10;i++) { s *= 10; }

  if(n > 3) {
    printf("%lld\n", s-n/3);
  } else if(n == 3) {
    if( strstr(t, "110") ) {
      printf("10000000000\n");
    } else {
      printf("%lld\n", s-n/3);
    }
  } else if(n == 2) {
    if( strstr(t, "11") ) {
      printf("10000000000\n");
    } else if( strstr(t, "10") ) {
      printf("10000000000\n");
    } else if( strstr(t, "01") ) {
      printf("9999999999\n");
    } else if( strstr(t, "00") ) {
      printf("0\n");
    }
  } else if(n == 1) {
    if( strstr(t, "1") ) {
      printf("20000000000\n");
    } else if( strstr(t, "0") ) {
      printf("10000000000\n");
    }
  }

  return 0;
}
