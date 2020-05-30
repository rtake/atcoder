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
  lint n; cin >> n;
  string s; cin >> s;

  vector<lint> l(n,0), r(n,0);
  for(lint i=1;i<n;i++) {
    l[i] = l[i-1];
    if(s[i-1] == 'W') { l[i]++; }
  }

  for(lint i=n-2;i>=0;i--) {
    r[i] = r[i+1];
    if(s[i+1] == 'E') { r[i]++; }
  }

  lint ans=n;
  for(lint i=0;i<n;i++) { ans = min(ans,r[i]+l[i]); }

  cout << ans << endl;
  return 0;
}