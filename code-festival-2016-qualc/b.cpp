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
  int k,t; cin >> k >> t;
  vector<int> a(t); for(int i=0;i<t;i++) { cin >> a[i]; }
  
  sort(a.begin(),a.end());
  int sum=0;
  for(int i=0;i<t-1;i++) { sum += a[i]; }
  
  cout << max(0,(a[t-1]-1)-sum) << endl;

  return 0;
}
