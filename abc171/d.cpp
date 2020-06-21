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
  vector<int> a(n); for(int i=0;i<n;i++) { cin >> a[i]; }
  lint q; cin >> q;
  vector<lint> b(q),c(q); for(int i=0;i<q;i++) { cin >> b[i] >> c[i]; }

  lint sum=0;
  vector<lint> d(100000,0);
  for(int i=0;i<n;i++) {
    sum += a[i];
    d[a[i]-1]++; 
  }

  for(int i=0;i<q;i++) {
    sum += (c[i]-b[i])*d[b[i]-1];
    d[c[i]-1] += d[b[i]-1];
    d[b[i]-1] = 0;
    cout << sum << endl;
  }
  return 0;
}
