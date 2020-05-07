# include <bits/stdc++.h>
using namespace std;

int main() { 
  string s; cin >> s;
  stringstream ss;
  int cnt;
  
  ss << s[0];
  cnt = 1;
  for(int i = 1;i < (int)s.size();i++) {
    if( s[i] == s[i-1] ) {
      cnt++;
    } else {
      ss << cnt << s[i];
      cnt = 1;
    }
  }
  ss << cnt;
  
  cout << ss.str() << endl;
  return 0;
}