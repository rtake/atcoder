# include <bits/stdc++.h>
using namespace std;

int main() {
  int n, num; cin >> n;
  map<string,int> m;
  string s, ans;

  for(int i = 0;i < n;i++) { cin >> s; m[s]++; }

  num = 0;
  for(map<string,int>::iterator it = m.begin();it != m.end();it++) {
    if(num < it->second) {
      num = it->second;
      ans = it->first;
    }
  }

  cout << ans << endl;
  return 0;
}