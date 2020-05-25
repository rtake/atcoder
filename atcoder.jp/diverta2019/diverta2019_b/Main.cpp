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
  int R,G,B,N; cin >> R >> G >> B >> N;

  lint ans=0;
  for(int r=0;r*R<=N;r++) {
    for(int g=0;r*R+g*G<=N;g++) {
      if((N-r*R-g*G)%B == 0 && N-r*R+g*G >= 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}