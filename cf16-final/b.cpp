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
  lint n; cin >> n;

  lint i;
  for(i=1;i<=n;i++) {
    if(i*(i+1)/2 >= n) { break; }
  }

  vector<lint> v;
  lint sum=0;
  for(lint j=i;j>=1;j--) {
    if(sum+j > n) { continue; }
    v.push_back(j);
    sum += j;
    if(sum == n) { break; }
  }

  for(lint j=0;j<(int)v.size();j++) { cout << v[j] << endl; }
  return 0;
}
