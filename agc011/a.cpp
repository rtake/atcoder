# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint n,c,k; cin >> n >> c >> k;
  vector<lint> t(n); for(lint i=0;i<n;i++) { cin >> t[i]; }

  sort(t.begin(),t.end()); // ok

  lint ans=1,cnt=1,index=0;
  for(lint i=1;i<n;i++) {

    if(t[i] <= t[index]+k) {
      cnt++;

      if(cnt >= c) {
        cnt = 0;
        ans++;
        index = i;
      }

    } else {
      cnt = 0;
      ans++;
      index = i;
    }

  }

  cout << ans << endl;
  return 0;
}
