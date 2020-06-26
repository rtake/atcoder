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
  lint n,m; cin >> n >> m;
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }
  vector<lint> b(m),c(m); for(lint i=0;i<m;i++) { cin >> b[i] >> c[i]; }

  priority_queue< lint, vector<lint>, greater<lint> > pq;
  for(lint i=0;i<n;i++) { pq.push(a[i]); }
  for(lint i=0;i<m;i++) {
    for(lint j=0;j<b[i];j++) {
      lint v=pq.top();
      if(v>=c[i]) { break; }
      pq.pop();
      pq.push(c[i]);
    }
  }

  lint sum=0;
  while(!pq.empty()) {
    sum += pq.top();
    pq.pop();
  }

  cout << sum << endl;
  return 0;
}