# include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int x, long long int y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

long long int lcm(long long int x, long long int y) { return abs(x-y)/gcd(x,y); }


int main() {
  long long int ans,n,m; cin >> n >> m;

  if(n>1 && m>1) { ans = (n-2)*(m-2); }
  else if(n==1) { ans = abs(m-2); }
  else if(m==1) { ans = abs(n-2); }

  cout << ans << endl;
  return 0;
}