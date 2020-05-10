# include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h); for(int i = 0;i < h;i++) { cin >> a[i]; }

  int check, nrow = h, ncol = w;
  /*
  for(int i = 0;i < nrow;i++) {
    check = 1;
    for(int j = 0;j < w;j++) {
      if(a[i][j] != '.') {
        check = -1;
        break;
      }
    }

    if(check == 1) {
      if(i < h-1) {
        for(int j = i;j < nrow-1;j++) { a[j] = a[j+1]; }
        i--;
      }
      nrow--;
    }
  } // row
  */

  for(int i = 0;i < ncol;i++) {

    check = 1;
    for(int j = 0;j < nrow;j++) {
      if(a[j][i] != '.') {
        check = -1;
        break;
      }
    }

    if(check == 1) {
      if(i < w-1) {
        for(int j = i;j < ncol;j++) {
          for(int k = 0;k < nrow;k++) { a[j][k] = a[j][i+1]; }
        }
        i--;
      }
      ncol--;
    }

  } // column

  for(int i = 0;i < nrow;i++) {
    for(int j = 0;j < ncol;j++) { cout << a[i][j]; }
    cout << endl;
  }

  return 0;
}
