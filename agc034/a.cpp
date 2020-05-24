# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint n,a,b,c,d; cin >> n >> a >> b >> c >> d;
  string s; cin >> s;

  if(s.find("##") < (int)s.size()) { cout << "No\n"; return 0; }
  if(c < d) { cout << "Yes\n"; return 0; }

  if(b-1 <= s.find("...")+1 && s.find("...")+1 < d-1) { cout << "Yes\n"; return 0; }

  cout << "No\n";
  return 0;
}
