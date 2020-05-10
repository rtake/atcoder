# include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m; cin >> n >> m;
  vector<int> ans(n,0), check(n,0);

  for(int i = 0;i < m;i++) {
    int c,s; cin >> s >> c;

    if(check[s-1] == 0) {
      ans[s-1] = c;
      check[s-1]++;
    } else{
      if(ans[s-1] != c) {
        ans[0] = -1;
      }
    }

  }

  if(ans[0] == 0) {
    if(n > 1) {
      if(check[0] != 0) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      cout << 0 << endl;
      return 0;
    }
  }

  if(ans[0] == -1) {
    cout << -1 << endl;
    return 0;
  }

  int sum = 0;
  for(int i = 0;i < n;i++) {
    if(check[i] == 0) {
      if(i == 0) { sum += pow(10,n-1); }
    }
    sum += ans[i] * pow(10,n-i-1);
  }
  cout << sum << endl;
  return 0;
}