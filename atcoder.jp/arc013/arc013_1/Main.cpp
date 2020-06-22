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
  int n,m,l,p,q,r; cin >> n >> m >> l >> p >> q >> r;
  
  int cnt0 = (n/p)*(m/q)*(l/r);
  int cnt1 = (n/p)*(l/q)*(m/r);
  int cnt2 = (m/p)*(l/q)*(n/r);
  int cnt3 = (m/p)*(n/q)*(l/r);
  int cnt4 = (l/p)*(m/q)*(n/r);
  int cnt5 = (l/p)*(n/q)*(m/r);

  cout << max(cnt0,max(cnt1,max(cnt2,max(cnt3,max(cnt4,cnt5))))) << endl;
  return 0;
}
