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
  vector<lint> a(n),b(m);
  for(lint i=0;i<n;i++) { cin >> a[i]; }
  for(lint i=0;i<m;i++) { cin >> b[i]; }

  if(m > n) {
    cout << "NO\n";
    return 0;
  }

  sort(a.begin(),a.end(),greater<lint>());
  sort(b.begin(),b.end(),greater<lint>());

  for(lint i=0;i<m;i++) {
    if(b[i] > a[i]) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  return 0;
}