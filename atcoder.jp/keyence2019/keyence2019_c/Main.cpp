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
  vector<lint> a(n),b(n);
  for(lint i=0;i<n;i++) { cin >> a[i]; }
  for(lint i=0;i<n;i++) { cin >> b[i]; }

/*
  if(accumulate(a.begin(),a.end(),0) < accumulate(b.begin(),b.end(),0)) {
    cout << -1 << endl;
    return 0;
  }
*/
  vector<lint> d(n); // diff
  for(lint i=0;i<n;i++) { d[i] = a[i]-b[i]; }
  sort(d.begin(),d.end());

  lint sum=0, cnt=0;
  for(lint i=0;i<n;i++) {
    if(d[i] < 0) {
      cnt++;
      sum += d[i];
    }
  }

  for(lint i=n-1;i>=0;i--) {
    if(sum < 0 && d[i] > 0) {
      sum += d[i];
      cnt++;
    }

    if(sum >= 0) {
      cout << cnt << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}