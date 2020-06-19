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
  string s,t; cin >> s >> t;
  int s_size = (int)s.size(), t_size = (int)t.size();

  for(int i=s_size;i>=0;i--) {
    if(s[i] == t[t_size-1] || s[i] == '?') {
      int l=1;
      string s0 = s;

      while(i-l+1>=0 && l<=t_size) {
        if(s[i-l+1] == '?') { s0[i-l+1] = t[t_size-l]; }
        else {
          if(s[i-l+1] != t[t_size-l]) { break; }
        }
        l++;
      }

      if(l == t_size+1) {
        for(int j=0;j<s_size;j++) {
          if(s0[j] == '?') { s0[j] = 'a'; }
        }
        cout << s0 << endl;
        return 0;        
      }
    }
  }

  cout << "UNRESTORABLE" << endl;
  return 0;
}
