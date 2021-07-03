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
  vector<int> a(n); for(int i=0;i<n;i++) { cin >> a[i]; }

  vector<int> l(n), r(n);
  l[0] = a[0];
  for(int i=1;i<n;i++) { l[i] = min(a[i],l[i-1]); }

  r[n-1] = a[n-1];
  for(int i=n-2;i>=0;i--) { r[i] = min(a[i],r[i+1]); }
  
  int ans=0, cnt=1;
  for(int i=n-2;i>=0;i--) {
    ans = max(ans, r[i+1]*((n-1)-i));
  }

  for(int i=1;i<n;i++) {
    ans = max(ans, l[i-1]*(i));
  }

  cout << ans << endl;
  return 0;
}
