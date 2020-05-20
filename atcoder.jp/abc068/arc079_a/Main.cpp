# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint n,m; cin >> n >> m;

  vector<int> v(n+1,0);
  for(lint i=0;i<m;i++) {
    lint a,b; cin >> a >> b;

    if(a == 1) {
      if(v[b] == n) {
        cout << "POSSIBLE\n";
        return 0;
      }
      v[b] = 1;
    } else if(b == n) {
      if(v[a] == 1) {
        cout << "POSSIBLE\n";
        return 0;
      }
      v[a] = n;
    }
  }

  cout << "IMPOSSIBLE\n";
  return 0;
}