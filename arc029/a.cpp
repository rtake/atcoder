# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n; cin >> n;
  vector<int> t(n,0); for(int i=0;i<n;i++) { cin >> t[i]; }

  int ans=200;
  for(int bit=0;bit<(1<<n);bit++) {
    int sum0=0,sum1=0;

    for(int i=0;i<n;i++) {
      if(bit & (1<<i)) {
        sum0 += t[i];
      } else {
        sum1 += t[i];
      }
    }

    ans = min(ans,max(sum0,sum1));
  }

  cout << ans << endl;
  return 0;
}
