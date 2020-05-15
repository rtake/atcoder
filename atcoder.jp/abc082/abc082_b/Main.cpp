# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  string s,t; cin >> s >> t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end(),greater<char>());
  if(s < t) { cout << "Yes\n"; return 0; }

  cout << "No\n";
  return 0;
}