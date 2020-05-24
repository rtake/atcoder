# include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

int lcm(int x, int y) { return x/gcd(x,y)*y; }


int main() {
  int n; cin >> n;
  vector<int> a(n); for(int i=0;i<n;i++) { cin >> a[i]; }

  int ans,sum=0;
  for(int i=0;i<n;i++) { sum += a[i]; }

  return 0;
}
