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


int main() {
  lint n; cin >> n;
  string a = "123456";

  for(lint i=0;i<n%30;i++) {
    char c=a[(i%5)];
    a[(i%5)] = a[(i%5)+1];
    a[(i%5)+1] = c;
  }

  cout << a << endl;
  return 0;
}
