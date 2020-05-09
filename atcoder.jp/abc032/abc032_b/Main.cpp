# include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  int k; cin >> k;

  int length = (int)s.size();
  set<string> ss;

  for(int index = 0;index + k - 1 < length;index++) {
    string buf;

    for(int j = 0;j < k;j++) { buf += s[index+j]; }
    ss.insert(buf);
  }

  cout << ss.size() << endl;

  return 0;
}