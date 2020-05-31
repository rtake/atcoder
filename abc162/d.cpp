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
  int size = (int)s.size();

  lint r=0,g=0,b=0;
  for(int i=0;i<size;i++) {
    if(s[i] == 'R') { r++; }
    else if(s[i] == 'G') { g++; }
    else if(s[i] == 'B') { b++; }
  }

  lint ans=r*g*b;

  for(int i=0;i<size;i++) {
    for(int j=i+1;j<size;j++) {
      if(2*j-i <= j || 2*j-i >= size) { continue; }
      if((s[i] != s[j]) && (s[j] != s[2*j-i]) && (s[2*j-i] != s[i])) { ans--; }
    }
  }

  cout << ans << endl;
  return 0;
}
