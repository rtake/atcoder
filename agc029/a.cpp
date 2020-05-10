# include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  vector<int> wpos;
  long long int ans = 0, last = (int)s.size() - 1;

  for(int i = 0;i <= last;i++) {
    if(s[i] == 'B') wpos.push_back(i);
  }

  for(int i = (int)wpos.size() - 1;i >= 0;i--) {
    ans += last - wpos[i];
    last--;
  }

  cout << ans << endl;
  return 0;
}
