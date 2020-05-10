# include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  map<long long int, int> m;
  int ans = 0;

  for(int i = 0;i < n;i++) {
    long long int a; cin >> a;

    if(m[a] == 0) { m[a]++; }
    else { m[a] = 0; }
  }

  for(map<long long int, int>::iterator it = m.begin();it != m.end();it++) { if(it->second > 0) { ans++; } }

  cout << ans << endl;
  return 0;
}
