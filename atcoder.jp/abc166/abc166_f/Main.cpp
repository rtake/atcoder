# include <iostream>
using namespace std;

int main(void) {
  int n, a[3]; cin >> n >> a[0] >> a[1] >> a[2];
  int ans[n], x[n][2];
  
  for(int i = 0;i < n;i++) {
    char s[3]; cin >> s; 
    for(int j = 0;j < 2;j++) { x[i][j] = s[j] - 'A'; } 
  }
  
  for(int i = 0;i < n;i++) {
    if( a[ x[i][0] ] == 0 && a[ x[i][1] ] == 0 ) { cout << "No\n"; return 0; }
    else if( a[ x[i][0] ] == 0 ) { a[ x[i][0] ]++; a[ x[i][1] ]--; ans[i] = x[i][0]; }
    else if( a[ x[i][1] ] == 0 ) { a[ x[i][1] ]++; a[ x[i][0] ]--; ans[i] = x[i][1]; }
    else {
      if( i < n - 1 && ( x[i][0] == x[i + 1][0] || x[i][0] == x[i + 1][1] ) ) {
        a[ x[i][0] ]++; a[ x[i][1] ]--; ans[i] = x[i][0];
      } else { a[ x[i][1] ]++; a[ x[i][0] ]--; ans[i] = x[i][1]; }
    }
  }
  
  cout << "Yes\n"; for(int i = 0;i < n;i++) { cout << (char)( ans[i] + 'A' ) << endl; }
  return 0;
}