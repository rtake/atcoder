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
  int n; cin >> n;
  string s; cin >> s;

  int num[2]={0,0}, l=0, r=0;
  for(int i=0;i<n;i++) {
    if(s[i] == '(') { l++; }
    else if(s[i] == ')') { l--; }

    if(s[n-i-1] == ')') { r++; }
    else if(s[n-i-1] == '(') { r--; }

    num[0] = min(num[0], l);
    num[1] = min(num[1], r);
  }

  for(int i=0;i<abs(num[0]);i++) {
    s = '(' + s;
  }

  for(int i=0;i<abs(num[1]);i++) {
    s = s + ')';
  }

  cout << s << endl;
  return 0;
}
