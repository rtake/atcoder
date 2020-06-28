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
  int h,w; cin >> h >> w;
  vector< vector<char> > s(h+2,vector<char>(w+2,'.'));
  for(int i=1;i<=h;i++) { for(int j=1;j<=w;j++) { cin >> s[i][j]; } }

  int check=0;
  for(int i=1;i<=h;i++) {
    for(int j=1;j<=w;j++) {
      if(s[i][j] == '#') {
        if(s[i][j-1] != '#' && s[i-1][j] != '#' && s[i+1][j] != '#' && s[i][j+1] != '#') {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
