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

  sort(a.begin(),a.end(),greater<lint>());

  vector<lint> lmax(2,0);
  for(lint i=1;i<n;i++) {
    if(a[i] == a[i-1]) {
      lmax.push_back(a[i]);
      i++;
    }
    if((int)lmax.size() >= 4) { break; }
  }

  sort(lmax.begin(),lmax.end(),greater<lint>());
  cout << lmax[0] * lmax[1] << endl;
  return 0;
}
