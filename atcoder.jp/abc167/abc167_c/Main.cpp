# include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,x; cin >> n >> m >> x;
  int c[12],a[12][12];
  for(int i = 0;i < n;i++) {
    cin >> c[i];
    for(int j = 0;j < m;j++) { cin >> a[i][j]; }
  }

  vector< vector<int> > mat(1,vector<int>(n,0));
  int ans = 0, check = 0, r, sum = 0;

  vector<int> vec(m,0);
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < m;j++) { vec[j] += a[i][j]; }
    ans += c[i];
  } // for each book

  for(int i = 0;i < m;i++) {
    if(vec[i] < x) { cout << -1 << endl; return 0; }
  }

  for(int i = 0;i < n;i++) {
    int msize = (int)mat.size();
    for(int j = 0;j < msize;j++) {
      vector<int> vec0 = mat[j];
      vec0[i] = 1;
      mat.push_back(vec0);
    } // for all matrix
  }

  for(int i = 0;i < (int)mat.size();i++) {
    check = 1;
    for(int j = 0;j < m;j++) {
      r = 0;
      for(int k = 0;k < n;k++) { r += mat[i][k] * a[k][j]; } // for all books
      if(r < x) { check = -1; break; }
    } // for all elements

    if(check == -1) { continue; }

    if(check == 1) {
      sum = 0;
      for(int j = 0;j < n;j++) { sum += mat[i][j] * c[j]; }
    }

    if(ans > sum) { ans = sum; }
  } // for all combination

  cout << ans << endl; 

  return 0;
}
