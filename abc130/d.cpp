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
  vector<lint> a(n+1); for(lint i=1;i<=n;i++) { cin >> a[i]; }

  lint l=1,r=1,ans=0,sum=0;
  for(l=1;l<=n;l++) {

    for(;r<=n;) {
      if(sum >= k) { break; }
      else { sum += a[r++]; }  
    } // right value

    if(sum<k) { break; } // the last element
    ans += n-r+1;
    sum -= a[l]; // remove the left element
  } // fix left value

  cout << ans << endl;
  return 0;
}
