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

  vector<lint> check(n,-1);
  lint cur=1, cnt=0;
  check[cur] = 1;

  for(cnt=1;;cnt++) {
    cur = a[cur-1];
    if(cur == 2) {
      cout << cnt << endl;
      return 0;
    }

    if(check[cur-1] == -1) { check[cur-1] = 1; }
    else { break; }
  }

  cout << -1 << endl;
  return 0;
}
