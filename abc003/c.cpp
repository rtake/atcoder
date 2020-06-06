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
  int n,k; cin >> n >> k;
  vector<int> r(n); for(int i=0;i<n;i++) { cin >> r[i]; }

  sort(r.begin(),r.end());

  double rate=0, power=1;
  for(int i=n-k;i<n;i++) {
    rate += (double)r[i]*power;
    power *= 2;
  }

  printf("%.10lf\n",rate/power);
  return 0;
}
