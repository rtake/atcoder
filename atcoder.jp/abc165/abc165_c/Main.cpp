# include <iostream>
# include <vector>
using namespace std;

vector< vector<int> > make_combination(int m,int n) {
  vector< vector<int> > combination;

  if( n == 1 ) { for(int i = 0;i < m;i++) { combination.push_back( vector<int>(1,i+1) ); }
  } else {
    for(int i = 0;i < m;i++) {
      vector< vector<int> > combination_0 = make_combination(m-i,n-1);
      for(int j = 0;j < (int)combination_0.size();j++) {
        combination_0[j].push_back(m-i);
        combination.push_back( combination_0[j] );
      }
    }
  }

  return combination;
}

int main() {
  int n,m,q,sum,sum_max; cin >> n >> m >> q;
  int a[q],b[q],c[q],d[q]; for(int i = 0;i < q;i++) { cin >> a[i] >> b[i] >> c[i] >> d[i]; }
  vector< vector<int> > A = make_combination(m,n);

  sum_max = 0;
  for(int i = 0;i < (int)A.size();i++) {
    sum = 0;
    for(int j = 0;j < q;j++) {
      if( A[i][ b[j] - 1 ] - A[i][ a[j] - 1 ] == c[j] ) { sum += d[j]; }
    }
    if( sum_max < sum ) { sum_max = sum; }
  }

  cout << sum_max << endl;
  return 0;
}
