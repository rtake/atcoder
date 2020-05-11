# include <bits/stdc++.h>
using namespace std;

int main() {
  int n,y; cin >> n >> y;

  for(int i = 0;i <= n;i++) {
    for(int j = 0;i+j <= n;j++) {
      int sum = 1000*i + 5000*j + 10000*(n-i-j);
      if(sum == y) {
        cout << n-i-j << " " << j << " " << i << endl;
        return 0;
      }
    } // 5000 yen
  } // 1000 yen

  cout << "-1 -1 -1\n";
  return 0;
}
