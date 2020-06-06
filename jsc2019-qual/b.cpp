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
  lint n,k; cin >> n >> k;
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  k %= 1000000007;

  lint ans=0;
  lint cnt0=0, cnt1=0;
  for(lint i=0;i<n;i++) {
    for(lint j=0;j<n;j++) {
      if(a[i] > a[j]) {
        cnt1++;
        if(i < j) { cnt0++; }
      }
    }
  }

  ans = (cnt0*k + (k*(k-1)/2)%1000000007*cnt1)%1000000007;
  cout << ans << endl;
  return 0;
}
