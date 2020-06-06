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
  string s,t; cin >> s >> t;
  
  if(s == t) {
    cout << "same\n";
    return 0;
  }

  for(int i=0;i<(int)s.size();i++) { s[i] = toupper(s[i]); }
  for(int i=0;i<(int)t.size();i++) { t[i] = toupper(t[i]); }
  if(s == t) {
    cout << "case-insensitive\n";
    return 0;
  }

  cout << "different\n";
  return 0;
}
