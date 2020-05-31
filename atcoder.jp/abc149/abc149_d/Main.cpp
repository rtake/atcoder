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
  lint n,k,r,s,p; cin >> n >> k >> r >> s >> p;
  string t; cin >> t;

  lint size=(lint)t.size(), ans=0;

  for(lint i=size-1;i>=0;i--) {
    if(i+k < size && t[i] == t[i+k]) { t[i] = 'x'; }
    if(t[i] == 'r') { ans += p; }
    else if(t[i] == 's') { ans += r; }
    else if(t[i] == 'p') { ans += s; }
  }

  cout << ans << endl;
  return 0;
}