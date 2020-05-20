# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint n; cin >> n;
  vector< vector<char> > c(n,vector<char>(10));
  for(lint i=0;i<n;i++) {
    for(lint j=0;j<10;j++) {
      cin >> c[i][j];
    }
  }

  lint ans=0;
  map<vector<char>,int> mp;
  for(lint i=0;i<n;i++) {
    sort(c[i].begin(),c[i].end());

    if(mp.find(c[i]) != mp.end()) { ans += mp.at(c[i]); }
    mp[c[i]]++;
  }

  cout << ans << endl;
  return 0;
}