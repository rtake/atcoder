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
  int n,m; cin >> n >> m;
  vector<lint> a(n),b(n); for(int i=0;i<n;i++) { cin >> a[i] >> b[i]; }
  vector<lint> c(m),d(m); for(int i=0;i<m;i++) { cin >> c[i] >> d[i]; }

  for(int i=0;i<n;i++) {
    lint distmin=9999999999;
    int jmin=0;
    for(int j=0;j<m;j++) {
      lint cur = abs(a[i]-c[j])+abs(b[i]-d[j]);
      if(distmin > cur) {
        jmin = j;
        distmin = cur;
      }
    }
    printf("%d\n",jmin+1);
  }

  return 0;
}
