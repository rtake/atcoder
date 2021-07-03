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
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  map<lint,lint> mp;
  for(auto x:a) { mp[x]++; }
 
  lint ans=n*(n-1)/2;
  for(auto y:mp) {
    lint cur = y.second;
    ans -= cur*(cur-1)/2;
  }

  printf("%lld\n", ans);
  return 0;
}
