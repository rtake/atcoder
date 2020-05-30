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
  lint n,m; cin >> n >> m;

  if(abs(n-m) >= 2) {
    cout << "0\n";
    return 0;
  }

  lint ans=1;
  if(n == m) { ans = ((P(n,n)*P(m,m)%1000000007)*2)%1000000007; }
  else { ans = (P(n,n)*P(m,m))%1000000007; }

  cout << ans << endl;
  return 0;
}