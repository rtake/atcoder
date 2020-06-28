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
  int n,x,y; cin >> n >> x >> y;
  
  vector< vector<int> > d(n+2,vector<int>(n+2,9999999)); // distance matrix
  vector<int> c(n+1,0);
  for(int i=1;i<=n-1;i++) { 
    for(int j=i+1;j<=n;j++) {
      d[i][j] = j-i;
      c[d[i][j]]++;
    }
  }

  c[d[x][y]]--;
  d[x][y]=1;
  c[d[x][y]]++;

  int check=0;
  while(check==0) {
    check=1;
    for(int i=1;i<=n-1;i++) {
      for(int j=i+1;j<=n;j++) {
        int d_0 = min(min(d[i-1][j],d[i+1][j]),min(d[i][j-1],d[i][j+1]))+1;
        if(d[i][j]>d_0) {
          c[d[i][j]]--;
          d[i][j] = d_0;
          c[d[i][j]]++;
          check=0;
        }
      }
    }
  }

  for(int i=1;i<=n-1;i++) { cout << c[i] << endl; }
  return 0;
}
