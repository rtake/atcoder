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
  vector<lint> d(n); for(lint i=0;i<n;i++) { cin >> d[i]; }

  if(d[0] != 0) {
    cout << 0 << endl;
    return 0;
  } 

  vector<lint> e(n,0);
  for(lint i=0;i<n;i++) { e[d[i]]++; }

  if(e[0] != 1) {
    cout << 0 << endl;
    return 0;
  }

  lint ans=1;
  for(lint i=2;i<n;i++) {
    for(int j=0;j<e[i];j++) {
      ans *= e[i-1]%998244353;
      ans %= 998244353;
    }
  }
  cout << ans << endl;
  return 0;
}
