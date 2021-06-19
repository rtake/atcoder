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
  vector<int> a(n+1,0),b(n+1,0),c(n+1,0);
  for(int i=1;i<=n;i++) { cin >> a[i];}
  for(int i=1;i<=n;i++) { cin >> b[i];}
  for(int i=1;i<=n;i++) { cin >> c[i];}

  vector<int> d(n+1,0);
  for(int i=1;i<=n;i++) { d[a[i]]++; }
  
  lint ans=0;
  for(int i=1;i<=n;i++) {
    ans += d[ b[c[i]] ];
  }

  cout << ans << endl;
  return 0;
}
