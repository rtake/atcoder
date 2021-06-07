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
  int l=(int)s.length();
  int start=0, end=l-1, xnum[2]={0,0};

  while(start <= end) {

    if(s[start] == s[end]) {
      start++;
      end--;
      continue;
    }

    while(s[start] == 'x') {
      start++;
      xnum[0]++;
    }

    while(s[end] == 'x') {
      end--;
      xnum[1]++;
    }

    if(s[start] != s[end]) {
      cout << "-1\n";
      return 0;
    }

    start++;
    end--;
  }

  cout << abs(xnum[0]+xnum[1]) << endl;
  return 0;
}