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
  int n,l; scanf("%d %d\n",&n,&l);
  vector<string> s(l+1); for(int i=0;i<l+1;i++) { getline(cin,s[i]); }

  int goal = s[l].find('o')/2;
  for(int i=l-1;i>=0;i--) {
    if(goal*2-1 >= 0 && s[i][goal*2-1] == '-') { goal--; }
    else if(goal*2+1 < 2*n && s[i][goal*2+1] == '-') { goal++; }
  }

  cout << goal+1 << endl;
  return 0;
}