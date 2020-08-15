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
  lint k; cin >> k;

  lint cur=7, ans=0, modsum=0;

  while(true) {
    modsum = ((cur%k)+modsum)%k;
    ans++;

    if(cur%k == 0) {
      // ans = -1;
      break;
    }

    if(modsum%k == 0) {
      break;
    }

    cur *= 10;
  }
  
  cout << ans << endl;
  return 0;
}
