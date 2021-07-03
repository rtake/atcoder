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
  int n; cin >> n;
  vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];

  vector<int> b=a, c=a;
  for(int i=1;i<n;i++) b[i] = b[i-1] + a[i];
  for(int i=1;i<n;i++) c[i] = c[i-1] + b[i];

  int i_max=0;
  for(int i=1;i<n;i++) {
    if(c[i] > c[i_max]) i_max=i;
  }

  // for(auto x:b) cout << x << endl;
  // for(auto x:c) cout << x << endl;

  int ans=0, test=c[i_max];
  for(int i=0;i<n;i++) {
    if(i > i_max) break;
    test += a[i];
    ans = max(ans,test);
  }

  cout << ans << endl;
  return 0;
}
