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
  string s; cin >> s;

  list<char> t;
  int l=s.size(), key=1;
  
  for(int i=0;i<l;i++) {
    if(s[i] == 'R') { 
      key *= -1;
    } else {
      if(key > 0) {
        if(t.back() == s[i]) t.pop_back();
        else t.push_back(s[i]);
      } else {
        if(t.front() == s[i]) t.pop_front();
        else t.push_front(s[i]);
      }
    }

  }

  if(key < 0) reverse(t.begin(), t.end());

  for(auto x: t) cout << x;
  cout << endl;

  return 0;
}
