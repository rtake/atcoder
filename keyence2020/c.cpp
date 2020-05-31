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
  lint n,k,s; cin >> n >> k >> s;

  vector<lint> a(n,(s+1)%1000000000);
  for(lint i=0;i<k;i++) { a[i] = s; }


  for(lint i=0;i<n;i++) { cout << a[i] << " "; }
  cout << endl;
  return 0;
}
