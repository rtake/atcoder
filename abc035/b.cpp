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


int main() {
  string s; cin >> s;
  int t; cin >> t;

  lint  l=0,r=0,u=0,d=0,q=0;
  for(int i=0;i<(int)s.size();i++) {
    if(s[i] == 'L') { l++; }
    else if(s[i] == 'R') { r++; }
    else if(s[i] == 'U') { u++; }
    else if(s[i] == 'D') { d++; }
    else { q++; }
  }

  lint ans;
  if(t == 1) { ans = abs(r-l)+abs(u-d)+q; }
  else if(t == 2) {
    if(abs(r-l)+abs(u-d)-q >= 0) { ans = abs(r-l)+abs(u-d)-q; }
    else {
      if( (q-(abs(r-l)+abs(u-d)))%2 == 0) { ans = 0; }
      else if( (q-(abs(r-l)+abs(u-d)))%2 == 1) { ans = 1; }
    }
  }

  cout << ans << endl;
  return 0;
}
