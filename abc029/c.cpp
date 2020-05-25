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
  int n; cin >> n;

  vector<string> s;
  s.push_back("a");
  s.push_back("b");
  s.push_back("c");

  for(lint i=2;i<=n;i++) {
    vector<string> t;
    
    for(lint j=0;j<(lint)s.size();j++) {
      t.push_back(s[j]+"a");
      t.push_back(s[j]+"b");
      t.push_back(s[j]+"c");
    } // for all elements in s

    s = t;
  }

  for(lint i=0;i<(lint)s.size();i++) { cout << s[i] << endl; }
  return 0;
}
