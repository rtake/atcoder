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

  string march="MARCH";
  map<char,lint> map;
  lint ans=0;

  for(int i=0;i<n;i++) { map[s[i][0]]++; }

  for(int i=0;i<5;i++) {
    for(int j=i+1;j<5;j++) {
      for(int k=j+1;k<5;k++) {
        ans += map[march[i]]*map[march[j]]*map[march[k]];
      }
    }
  }

  cout << ans << endl;
  return 0;
}
