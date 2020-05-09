# include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  char x[n][9]; for(int i = 0;i < n;i++) { cin >> x[i]; }

  int ans = 0;
  vector<int> stat(9,0);

  for(int i = 0;i < n;i++) {

    for(int j = 0;j < 9;j++) {
      if(x[i][j] == 'o') { stat[j] = 1; continue; }
      else if(x[i][j] == 'x') { ans++; }

      if(stat[j] == 1) { stat[j] = 0; ans++; }
    }

    // for(int j = 0;j < 9;j++) { cout << stat[j] << " "; }
    // cout << endl;
  }

  for(int j = 0;j < 9;j++) { ans += stat[j]; }
  cout << ans << endl;

  return 0;
}