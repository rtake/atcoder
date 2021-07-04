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
  vector<int> a(m+2); for(int i=1;i<m+1;i++) cin >> a[i];

  a[0] = 0;
  a[m+1] = n+1;
  sort(a.begin(), a.end());

  int k=n;
  vector<int> b(m+1);
  for(int i=0;i<m+1;i++) {
    b[i] = a[i+1] - a[i] - 1;
    if(b[i] > 0) k = min(k, b[i]);
  }

  int ans=0;
  for(auto x:b) ans += (x+k-1)/k;

  printf("%d\n", ans);
  return 0;
}