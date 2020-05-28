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


int main() {
  lint n; cin >> n;
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  lint ans=0;
  vector<lint> b(n+1,0);
  for(lint i=0;i<n;i++) {
    if(a[i] <= n) { b[a[i]]++; }
    else { ans++; }
  }

  for(lint i=1;i<=n;i++) {
    if(b[i] == i) { continue; }
    else if(b[i] > i) { ans += b[i]-i; }
    else if(b[i] < i) { ans += b[i]; }
  }

  cout << ans << endl;
  return 0;
}