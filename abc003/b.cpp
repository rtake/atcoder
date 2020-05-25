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
  string s,t; cin >> s >> t;

  int size = (int)s.size();
  string atcoder = "atcoder";

  for(int i=0;i<size;i++) {
    if(s[i] == t[i]) { continue; }
    if(s[i] == '@' && atcoder.find(t[i]) != string::npos) { continue; }
    if(t[i] == '@' && atcoder.find(s[i]) != string::npos) { continue; }
    if(s[i] == '@' && t[i] == '@') { continue; }
    cout << "You will lose\n";
    return 0;
  }

  cout << "You can win\n";
  return 0;
}
