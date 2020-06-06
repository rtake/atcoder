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
  int size=(int)s.size();

  if(s[0] == s[size-1]) { ans += k; }

  for(int i=0;i<size-1;) {
    int l=1;
    while(l+i < size-1 && s[l+i] == s[i]) { l++; }
    i += l;
    ans += (l/2)*k;
  }

  cout << ans << endl;
  return 0;
}
