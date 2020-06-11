# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

lint C(lint n, lint k) {
  if(n == k) { return 1; }
  else if(n < k) { return 0; }
  else if(k == 0) { return 1; }
  else if(k == 1) { return n; }
  else return C(n-1,k-1) + C(n-1,k);
}

lint P(lint n, lint k) {
  if(k == 1) { return n; }
  return (n*(P(n-1,k-1)%1000000007)%1000000007);
}


int main() {
  int n,m; cin >> n >> m;
  vector< vector<int> > mat(n,vector<int>(n,0));

  for(int i=0;i<m;i++) {
    int a,b; cin >> a >> b;
    mat[a-1][b-1] = 1;
    mat[b-1][a-1] = 1;
  }

/*
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout << mat[i][j];
    }
    cout << endl;
  }
*/

  for(int i=0;i<n;i++) {

    vector<int> check(n,0);
    for(int j=0;j<n;j++) {
      if(mat[i][j] == 0) { continue; } // i and j is not connect
      for(int k=0;k<n;k++) {
        if(mat[j][k] == 0) { continue; }
        if(mat[i][k] == 1) { continue; } // k is connect to i
        if(k == i) { continue; } // k is i
        check[k] = 1;
      }
    }

    int sum=0;
    for(int j=0;j<n;j++) { sum += check[j]; }
    cout << sum << endl;
  }

  return 0;
}
