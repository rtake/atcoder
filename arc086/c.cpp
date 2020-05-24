# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint n,k; cin >> n >> k;
  vector<int> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  vector<int> b(n,0);
  for(lint i=0;i<n;i++) { b[a[i]-1]++; }
  sort(b.begin(),b.end(),greater<int>());

  lint ans=0;
  for(lint i=k;i<n;i++) { ans += b[i]; }

  cout << ans << endl;
  return 0;
}
