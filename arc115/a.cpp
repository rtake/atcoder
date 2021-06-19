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
  int n,m;
  scanf("%d %d\n", &n, &m);
  char s[n][m];
  for(int i=0;i<n;i++) { scanf("%s\n", s[i]); }

  int ans=0;
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      int check=0;
      for(int k=0;k<m;k++) {
        if(s[i][k] != s[j][k]) {
          check++;
        }
      }

      if(check %2 == 1) { ans++; }
    }
  }

  printf("%d\n", ans);
  return 0;
}
