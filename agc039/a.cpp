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
  lint k; cin >> k;

  lint ans=0;
  string ss = s+s;

  for(lint i=1;i<(lint)ss.size()-1;i++) {
    if(ss[i-1] == ss[i] && ss[i] == ss[i+1]) {
      ss[i] = 'X';
      ans += k/2+k%2;
    }
  }

  for(lint i=0;i<(lint)ss.size()-1;i++) {
    if(ss[i] == ss[i+1]) {
      s[i+1] = 'X';
      ans += k/2+k%2;
    }
  }

  cout << ans << endl;
  return 0;
}
