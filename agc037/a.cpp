# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  string s; cin >> s;

  lint k=1, l=1;
  for(lint i=1;i<(lint)s.size();i++) {

    if(s[i] == s[i-1]) {
      if(l == 1) {
        if(i == (lint)s.size()-1) {
          k--; // last word
        } else {
          l=2;
          i++;
        }
      } else {
        l=1;
      }

    } else { l=1; }

    k++;
  }

  cout << k << endl;
  return 0;
}
