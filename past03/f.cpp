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
  vector<string> a(n); for(int i=0;i<n;i++) { cin >> a[i]; }

  string s=a[n/2];

  for(int i=0;i<n/2;i++) {
    int check = 0;
    map<char,int> mp;

    for(int j=0;j<n;j++) { mp[a[i][j]]++; }
    for(int j=0;j<n;j++) {
      if(mp[a[n-1-i][j]] > 0) {
        s[i] = a[n-1-i][j]; s[n-1-i] = a[n-1-i][j];
        check = 1;
        break;
      }
    }

    if(check == 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << s << endl;
  return 0;
}
