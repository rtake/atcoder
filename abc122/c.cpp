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
  lint n,q; cin >> n >> q;
  string s; cin >> s;

  vector<lint> a(n);
  a[0] = 0;
  for(lint i=1;i<n;i++) {
    a[i] = a[i-1];
    if(s[i-1] == 'A' && s[i] == 'C') { a[i]++; }
    //cout << a[i] << endl;
  }
  
  vector<lint> ans(q);
  for(lint i=0;i<q;i++) {
    lint l,r; cin >> l >> r;
    ans[i] = a[r-1]-a[l-1];
  }

  for(lint i=0;i<q;i++) { cout << ans[i] << endl; }
  return 0;
}
