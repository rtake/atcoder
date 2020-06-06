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


int main() { // gathering <RL> RRLLLLRLRRLL
  string s; cin >> s;

  int size=(int)s.size();
  vector<lint> l(size,0), r(size,0), a(size);

  for(int i=0;i<size-1;i++) {
    if(s[i] == 'R') { r[i+1] = r[i]; }
    else if(s[i] == 'L') { r[i+1] = i+1; }
  }

  for(int i=size-1;i>=0;i--) {
    l[i] = l[i+1];
    if(s[i] == 'L') { l[i]++; }
  }

  return 0;
}
