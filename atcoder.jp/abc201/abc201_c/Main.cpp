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
  int ok=0,ng=0,un=0;

  for(int i=0;i<10;i++) {
    if(s[i] == 'o') ok++;
    else if(s[i] == 'x') ng++;
    else if(s[i] == '?') un++;
  }

  int ans=0;
  if(ok > 4) {
    ans = 0;
  } else if(ok == 4) {
    ans = 4*3*2*1;
  } else if(ok == 3) {
    ans = 3*(4*3*2*1/(2*1));
    ans += un*(4*3*2*1); // 3*(4!/2!)
  } else if(ok == 2) {
    ans = 2*2*2*2 - 2;
    ans += 4*(2*2*2-2)*un ;
    ans += (4*3*2*1/(2*1))*un*un;
  } else if(ok == 1) {
    ans = 1;
    ans += 4*un;
    ans += (4*3*2*1/(2*1*2*1))*un*un;
    ans += 4*(un*un*un);
  } else if(ok == 0) {
    ans = un*un*un*un;
  }

  cout << ans << endl;
  return 0;
}