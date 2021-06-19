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
  lint n,q; cin >> n >> q;
  vector<lint> a(n+1,0); for(lint i=1;i<=n;i++) { cin >> a[i]; }
  vector<lint> k(q,0); for(lint i=0;i<q;i++) { cin >> k[i]; }
  
  vector<lint> b(n+2,0);
  b[0] = 0;
  b[1] = a[1]-1;
  b[n+1] = 999999999999999999;
  for(lint i=2;i<n;i++) {
    b[i] =  b[i-1] + (a[i] - a[i-1])-1;
    // cout << b[i] << endl;
  }

  for(lint i=0;i<q;i++) {
  // for(lint i=0;i<1;i++) {
    lint ans;
    lint l=b[0], r=b[n+1], pos=n/2;

    while(l != r) {
      // if(pos <= b[0] || b[n+1] <= pos) break;

      if(k[i] <= b[pos]) {
        if(b[pos-1] < k[i]) { 
          pos;
          // cout << b[pos-1] << endl;
          break; // a[pos-1] < (k) <= a[pos]
        } else if(b[pos-1] >= k[i]) {
          r = pos;
        }
      } else if(b[pos] < k[i]) {
        l = pos;
      }

      pos = (l+r)/2;
    }

    printf("%lld, %lld\n", pos, (a[pos]-1) - (b[pos] - k[i]) );
  }

  return 0;
}
