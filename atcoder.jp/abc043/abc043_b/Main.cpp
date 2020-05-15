# include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;

  int size = (int)s.size(), index=0;
  string ans = "          ";
  for(int i = 0;i < size;i++) {
    if(s[i] == 'B') {
      if(index > 0) {
        index--;
        ans[index] = ' ';
      }
    } else {
      ans[index] = s[i];
      index++;
    }
  }

  cout << ans << endl;
  return 0;
}