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
  int n;
  scanf("%d\n", &n);
  lint c[n][n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      scanf("%lld ", &c[i][j]);
    }
  }

  vector<lint> a(n,0), b(n,0);
  for(int i=1;i<n;i++) { a[i] = c[i][0]-c[i-1][0]; }
  for(int j=1;j<n;j++) { b[j] = c[0][j]-c[0][j-1]; }

  for(int i=1;i<n;i++) {
    for(int j=1;j<n;j++) {
      if(c[i][j] - c[i][j-1] == a[i] | c[i][j] - c[i][j-1] == b[j]) {
        continue;
      } else {
        printf("No\n");
        return 0;
      }
    }
  }

  printf("Yes\n");
  a[0] = c[0][0];
  for(int i=1;i<n;i++) { a[i] += a[i-1]; }
  for(int i=0;i<n;i++) { printf("%lld ", a[i]); }
  printf("\n");

  b[0] = 0;
  for(int i=1;i<n;i++) { b[i] += b[i-1]; }
  for(int i=0;i<n;i++) { printf("%lld ", b[i]); }
  printf("\n");

  return 0;
}
