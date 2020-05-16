# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n; cin >> n;
  vector<string> s(n); for(int i=0;i<n;i++) { cin >> s[i]; }

  for(int i=0;i<n;i++) { reverse(s[i].begin(),s[i].end()); }
  sort(s.begin(),s.end());
  for(int i=0;i<n;i++) {
    reverse(s[i].begin(),s[i].end());
    cout << s[i] << endl;
  }


  return 0;
}
