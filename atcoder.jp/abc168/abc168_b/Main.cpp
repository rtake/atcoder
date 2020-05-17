# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int k; cin >> k;
  string s; cin >> s;
  int size = (int)s.size();

  if(size <= k) { cout << s << endl; }
  else {
    for(int i=0;i<k;i++) { cout << s[i]; }
    cout << "...\n";
  }

  return 0;
}