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
  char s[h][w]; for(int i=0;i<h;i++) { cin >> s[i]; }

  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if(s[i][j] == '#') { continue; }

      int cnt=0;
      for(int k=i-1;k<i+2;k++) {
        if(k < 0 || k > h-1) { continue; }
        for(int l=j-1;l<j+2;l++) {
          if(l < 0 || l > w-1) { continue; }
          if(s[k][l] == '#') { cnt++; }
        }
      }

      s[i][j] = '0' + cnt; //cout << cnt << endl;
    }
  }

  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) { cout << s[i][j]; }
    cout << endl;
  }

  return 0;
}
