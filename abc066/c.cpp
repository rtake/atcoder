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
  lint n; cin >> n;
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  vector<lint> b(n);

  lint i=0;
  for(i=0;i<(n+1)/2;i++) { b[i] = a[n-2*i-1]; }
  for(i=0;i<(n+1)/2;i++) { b[i+(n+1)/2] = a[2*i+n%2]; }


  for(lint i=0;i<n;i++) { cout << b[i] << " "; }
  cout << endl;
  return 0;
}
