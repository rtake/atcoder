# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n; cin >> n;
  vector<lint> a(n), b(n); for(int i=0;i<n;i++) { cin >> a[i] >> b[i]; }

  lint sum=0;
  for(int i=0;i<n;i++) {
    vector<int> c(1,i);

      


  }

  return 0;
}
