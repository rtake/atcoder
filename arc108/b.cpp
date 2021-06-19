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
  int n;
  scanf("%d", &n);
  char s[n];
  scanf("%s", s);

  int depth=0, ans=0;
  char last;
  for(int i=0;i<n;i++) {

    if(s[i] == 'f') {

      if(last == 'f') { 
        depth++;
      } else if(last == 'o') {
        last = 'f';
        depth++;
      } else if(last == 'x') {
      } else {
      }

    } else if(s[i] == 'o') {

      if(last == 'f') { 
        last = 'o';
      } else if(last == 'o') {
        depth++;
      } else if(last == 'x') { 
        if(depth > 0) {
          // depth--;
        } else {
          last = '0';
        }
      } else { continue; }

    } else if(s[i] == 'x') {

      if(last == 'o') {
        ans++;
        last = 'x';
      } else if(last == 'x') {
        if(depth > 0) {
          depth--;
          ans++;
        } else {
          last = '0';
        }
      } else { continue; }

    }

  }

  /*
  char last=s[0];
  for(int i=1;i<n;i++) {
    if(last == 'f') {

    } else if(last == 'o') {

    } else if(last == 'x') {
      if(s[i] == 'f') {

      } else if(s[i] == 'o') {

      } else if(s[i] == 'x') {

      }
    }
  }
  */

  return 0;
}
