# include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m; cin >> n >> m;
  vector<int> x(m); for(int i = 0;i < m;i++) { cin >> x[i]; }
  sort(x.begin(),x.end());

  int ans = 0;
  vector<int> y(m-1); for(int i = 0;i < m-1;i++) { y[i] = x[i+1]-x[i]; }
  sort(y.begin(),y.end());

  for(int i = 0;i+n < m;i++) { ans += y[i]; }
  cout << ans << endl;
  return 0;
}
