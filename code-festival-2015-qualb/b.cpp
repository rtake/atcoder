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
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  vector<lint> b(m+1,0);
  for(lint i=0;i<n;i++) { b[a[i]]++; }

  for(lint i=0;i<=m;i++) {
    if(b[i] > n/2) {
      cout << i << endl;
      return 0;
    }
  }

  cout << "?\n";
  return 0;
}
