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
  int n; scanf("%d", &n);
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) { scanf("%d ", &a[i]); }
  for(int i=0;i<n;i++) { scanf("%d ", &b[i]); }

  int ans=0;
  int lower_b=-9999, upper_b=9999;

  for(int i=0;i<n;i++) {
    lower_b = max(lower_b,a[i]);
    upper_b = min(upper_b,b[i]);
  }

  cout << max(upper_b-lower_b+1,0) << endl;

  /*
  int max_a = *max_element(a.begin(), a.end());
  int min_b = *max_element(b.begin(), b.end());

  cout << max((min_b-max_a-1),0) << endl;
  */

  return 0;
}
