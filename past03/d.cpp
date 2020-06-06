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


char convert(string s1, string s2, string s3, string s4, string s5) {
  if(s1 == ".#.") { return '1'; }
  else if(s1 == "#.#") { return '4'; }
  else {
    if(s5 == "..#") { return '7'; }
    else {
      if(s3 == "#.#") { return '0'; }
      else {
        if(s4 == "#..") { return '2'; }
        else if(s4 == "#.#") {
          if(s2 == "#.#") { return '8'; }
          else { return '6'; }
        } else {
          if(s2 == "..#") { return '3'; }
          else if(s2 == "#..") { return '5'; }
          else { return '9'; }
        }
      }
    }
  }
}


int main() {
  int n; cin >> n;
  string s1,s2,s3,s4,s5; cin >> s1 >> s2 >> s3 >> s4 >> s5;

  char ans[n];

  for(int i=0;i<n;i++) {
    ans[i] = convert(s1.substr(4*i+1,3), s2.substr(4*i+1,3), s3.substr(4*i+1,3), s4.substr(4*i+1,3), s5.substr(4*i+1,3) );
    cout << ans[i];
  }

  cout << endl;
  return 0;
}
