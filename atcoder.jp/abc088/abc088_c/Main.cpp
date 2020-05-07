# include <bits/stdc++.h>
using namespace std;

int main() {
  int c[3][3], d[3][3], e[3][3];
  for(int i = 0;i < 3;i++) { cin >> c[i][0] >> c[i][1] >> c[i][2]; }

  for(int i = 0;i < 3;i++) {
    d[i][0] = c[i][1] - c[i][0]; d[i][1] = c[i][2] - c[i][1]; d[i][2] = c[i][0] - c[i][2];
  }
 
  for(int i = 0;i < 3;i++) {
    e[0][i] = c[1][i] - c[0][i];
    e[1][i] = c[2][i] - c[1][i];
    e[2][i] = c[0][i] - c[2][i];
  }

  for(int i = 0;i < 3;i++) {
    if( d[0][i] != d[1][i] || d[1][i] != d[2][i] || d[2][i] != d[0][i] ) {
      cout << "No\n";
      return 0;
    }
  }
  
  for(int i = 0;i < 3;i++) {
    if( e[i][0] != e[i][1] || e[i][1] != e[i][2] || e[i][2] != e[i][0] ) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";  
  return 0;
}