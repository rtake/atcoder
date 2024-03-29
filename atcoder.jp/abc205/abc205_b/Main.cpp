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
  int n; cin >> n;
  vector<int> a(n,0); for(int i=0;i<n;i++) { cin >> a[i]; }

  vector<int> b(n+1,0);
  for(int i=0;i<n;i++) { b[a[i]]++; }
  for(int i=1;i<=n;i++) {
    if(b[i] == 0) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  return 0;
}