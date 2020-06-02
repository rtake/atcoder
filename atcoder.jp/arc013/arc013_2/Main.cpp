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
  lint c; cin >> c;
  vector<lint> n(c), m(c), l(c); for(lint i=0;i<c;i++) { cin >> n[i] >> m[i] >> l[i]; }

  lint a0=0,a1=0,a2=0;
  for(lint i=0;i<c;i++) {
    vector<lint> b;
    b.push_back(n[i]);
    b.push_back(m[i]);
    b.push_back(l[i]);
    sort(b.begin(),b.end());

    a0 = max(a0,b[0]);
    a1 = max(a1,b[1]);
    a2 = max(a2,b[2]);
  }

  cout << a0*a1*a2 << endl;
  return 0;
}
