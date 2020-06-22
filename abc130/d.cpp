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

  lint sum=0, ans=0, l=0, r=0;
  for(r=0;r<n;r++) {
    sum += a[r];
    if(sum >= k) { break; }
  }

  while(true) {
    if(sum >= k) { 
      ans += (n-r);
      while(l<r) {
        sum -= a[l];
        l++;
        if(sum < k) { break; }
        ans++;
      } // fix r 
    }
    r++;
    if(r >= n) { break; }
    sum += a[r];
  }

  cout << ans << endl;
  return 0;
}
