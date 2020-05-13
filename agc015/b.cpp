# include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  int size = (int)s.size();

  long long int ans = 0;
  for(int i = 0;i < size;i++) {
    if(s[i] == 'U') { ans = ans + (size-i-1) + 2*i; }
    else if(s[i] == 'D') { ans = ans + 2*(size-i-1) + i; }
  }

  cout << ans << endl;
  return 0;
}
