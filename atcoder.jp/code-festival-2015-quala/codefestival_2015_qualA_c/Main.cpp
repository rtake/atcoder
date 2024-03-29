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
  lint n,t; cin >> n >> t;
  vector<lint> a(n),b(n); for(lint i=0;i<n;i++) { cin >> a[i] >> b[i]; }

  vector<lint> d(n);
  for(lint i=0;i<n;i++) { d[i] = a[i]-b[i]; }
  sort(d.begin(),d.end(),greater<lint>());

  lint sum=0;
  for(lint i=0;i<n;i++) { sum += a[i]; }

  lint cnt=0;
  if(sum <= t) {
    cout <<  cnt << endl;
    return 0;
  }

  for(lint i=0;i<n;i++) {
    sum -= d[i];
    cnt++;
    if(sum <= t) {
      cout << cnt << endl;
      return 0;
    }
  }

  cout <<-1 << endl;
  return 0;
}
