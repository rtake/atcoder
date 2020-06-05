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
  vector<lint> b(n); for(lint i=1;i<n;i++) { cin >> b[i]; }

  vector<lint> s_min(n,999999), s_max(n,0), s(n,1);

  for(lint i=n-1;i>0;i--) {
    if(s_min[i] <= s_max[i]) { s[i] = s_min[i] + s_max[i] + 1; }
    s_min[b[i]-1] = min(s_min[b[i]-1],s[i]);
    s_max[b[i]-1] = max(s_max[b[i]-1],s[i]);
  }

  cout << s_min[0] + s_max[0] + 1 << endl;
  return 0;
}