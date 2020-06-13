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
  lint n,k; cin >> n >> k;
  vector<lint> a(n); for(int i=0;i<n;i++) { cin >> a[i]; }

  for(int i=0;i<k;i++) {
    vector<lint> c(n+1,0);
    for(int j=0;j<n;j++) {
      c[max(0LL,j-a[j])]++;
      c[min(j+a[j]+1,n)]--;
    }

    a[0] = c[0];
    for(int j=1;j<n;j++) { a[j] = c[j]+a[j-1]; }

    int check=1;
    for(int j=0;j<n;j++) { if(a[j] != n){ check *= 0;} }
    if(check == 1) { break; }
  }

  for(int i=0;i<n;i++) { cout << a[i] << " "; }
  cout << endl;
  return 0;
}
