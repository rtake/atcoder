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
  int x,n; cin >> x >> n;
  if(n == 0) { 
    cout << x << endl;
    return 0;
  }

  vector<int> p(n); for(int i=0;i<n;i++) { cin >> p[i]; }
  sort(p.begin(),p.end());

  int ans=999999;
  for(int i=0;i<=101;i++) {
    if(find(p.begin(),p.end(),i) != p.end()) { continue; }
    if(abs(x-i) < abs(x-ans)) { ans = i; }
  }

  cout << ans << endl;
  return 0;
}
