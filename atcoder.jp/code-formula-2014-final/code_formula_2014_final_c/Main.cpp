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
  string s; getline(cin,s);
  s += '\n';

  set<string>st;
  for(int begin=0;begin<(int)s.size();begin++) {
    if(s[begin] == '@') {
      int length;

      for(;begin<(int)s.size();begin++) {
        if(s[begin] != '@') { break; }
      } // find last '@'

      for(length=1;begin+length-1<(int)s.size();length++) {
        if(s[begin+length-1] == ' ') {
          string t = s.substr(begin,length-1);
          if(t != "" && t != " ") { st.insert(t); }
          break;
        } else if(s[begin+length-1] == '@') {
          string t = s.substr(begin,length-1);
          if(t != "" && t != " ") { st.insert(t); }
          begin--;
          break;
        } else if(s[begin+length-1] == '\n') {
          string t = s.substr(begin,length-1);
          if(t != "" && t != " ") { st.insert(t); }
          break;
        }


      }

      begin += length-1;
    }

  }


  for(set<string>::iterator i=st.begin();i!=st.end();i++) { cout << *i << endl; }
  return 0;
}