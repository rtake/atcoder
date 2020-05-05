# include <iostream>
# include <vector>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  if( n%2 == 1) { for(int i = 0;i < m;i++) { cout << i+1 << " " << n-i << endl; } }
  else {
    for(int i = 0;i < m;i++) {
      if( i % 2 == 0) { cout << i/2 + 1 << " " << n - i/2 << endl; }
      else { cout << n/2 - i/2 - 1 << " " << n/2 + i/2 + 1 << endl; }
    }
  }
  return 0;
}