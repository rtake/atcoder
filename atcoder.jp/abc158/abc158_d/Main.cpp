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
  string s; cin >> s;
  int q; cin >> q;

  deque<char> dq;
  for(int i=0;i<(int)s.size();i++) { dq.push_back(s[i]); }

  int check=1;
  for(int i=0;i<q;i++) {
    int t; cin >> t;

    if(t == 1) {

      if(check == 1) { check = -1; }
      else { check = 1; }

    } else {

      int f; cin >> f;
      char c; cin >> c;
      if(f == 1) {
        if(check == 1) { dq.push_front(c); }
        else { dq.push_back(c); }
      } else {
        if(check == 1) { dq.push_back(c); }
        else { dq.push_front(c); }
      }

    }
  }

  if(check == -1) { reverse(dq.begin(),dq.end()); }
  for(deque<char>::iterator i=dq.begin();i!=dq.end();i++) { cout << *i; }
  cout << endl;
  return 0;
}