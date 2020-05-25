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
  lint n,m; cin >> n >> m;

  vector<lint> a(n,1),c(n,0);
  c[0] = 1;

  for(lint i=0;i<m;i++) {
    lint x,y; cin >> x >> y;
    a[x-1]--;
    a[y-1]++;
    if(c[x-1] == 1 && c[y-1] == 0) { c[y-1] = 1; }
    if(a[x-1] == 0) { c[x-1] = 0; }
  }

  lint ans=0;
  for(lint i=0;i<n;i++) { ans += c[i]; }
  cout << ans << endl;

  return 0;
}