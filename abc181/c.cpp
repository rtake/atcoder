# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%1000000007;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
}


int main() {
  int n; cin >> n;
  vector<int> x(n), y(n); for(int i=0;i<n;i++) cin >> x[i] >> y[i];

  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      for(int k=j+1;k<n;k++) {
        lint a[2], b[2];
        a[0] = x[j]-x[i]; a[1] = y[j]-y[i];
        b[0] = x[k]-x[j]; b[1] = y[k]-y[j];

        lint p = a[0]*b[0] + a[1]*b[1];
        lint a_abs=a[0]*a[0]+a[1]*a[1];
        lint b_abs=b[0]*b[0]+b[1]*b[1];

        if(p*p == a_abs*b_abs) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  
  cout << "No" << endl;
  return 0;
}
