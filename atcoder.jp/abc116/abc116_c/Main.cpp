# include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> h(n+1,0); for(int i = 0;i < n;i++) { cin >> h[i]; }

  int ans = 0;
  while(true) {

    int check = 1;
    for(int i = 0;i < n;i++) {
      if(h[i] > 0) {
        if(h[i+1] == 0) { ans++; }
        h[i]--;
        check *= 0;
      }
    }

    if(check == 1) { break; }
  }

  cout << ans << endl;
  return 0;
}