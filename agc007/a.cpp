# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int h,w; cin >> h >> w;
  char a[h][w]; for(int i=0;i<h;i++) { for(int j=0;j<w;j++) { cin >> a[i][j]; } }

  int cnt=0;
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if(a[i][j] == '#') { cnt++; }
    }
  }

  if(cnt == h+w-1) { cout << "Possible\n"; }
  else { cout << "Impossible\n"; }
  return 0;
}
