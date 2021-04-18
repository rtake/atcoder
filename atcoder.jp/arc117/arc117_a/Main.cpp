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
  int A, B;
  scanf("%d %d", &A, &B);

  lint a[A+B];
  int diff=abs(A-B);

  if(A==B) {
    for(int i=0;i<A;i++) { a[i] = i+1; }
    for(int i=0;i<B;i++) { a[i+A] = -(i+1); }
  } else if(A>B) {

    lint sum=0;
    for(int i=0;i<A;i++) {
      a[i] = i+1;
      sum += a[i];
    }

    for(int i=0;i<B-1;i++) {
      a[i+A] = -(i+1);
      sum += a[i+A];
    }

    a[A+B-1] = -sum;

  } else { // A<B

    lint sum=0;
    for(int i=0;i<B;i++) {
      a[i+A] = -(i+1);
      sum += a[i+A];
    }

    for(int i=0;i<A-1;i++) {
      a[i] = i+1;
      sum += a[i];
    }

    a[A-1] = -sum;
  }

  for(int i=0;i<A+B;i++) { printf("%lld ", a[i]); }
  printf("\n");

  return 0;
}