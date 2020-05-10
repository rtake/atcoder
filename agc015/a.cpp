# include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n,a,b; cin >> n >> a >> b;
  long long int ans = 0;

  if(a > b) {
    cout << 0 << endl;
    return 0;
  } else if(a == b) {
    cout << 1 << endl;
    return 0;
  } else if(a < b) {
    if(n == 1) { ans = 0; }
    else if(n >= 2) { ans = (n-2)*(b-a) + 1; }
    cout << ans << endl;
    return 0;
  }
}
