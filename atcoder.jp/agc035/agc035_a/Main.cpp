# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint n; cin >> n;
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  map<lint,lint> mp;
  for(lint i=0;i<n;i++) { mp[a[i]]++; }

  sort(a.begin(),a.end());

  if(a[n-1] == 0) { cout << "Yes\n"; return 0; } // all zero
  if(n%3 != 0) { cout << "No\n"; return 0; }
  if(mp.size() > 3) { cout << "No\n"; return 0; }

  if(mp.size() == 2) {
    if(mp[0] == n/3 && mp[a[n/3]] == n/3*2) { cout << "Yes\n"; return 0; }
  } else if(mp.size() == 3) {
    if(mp[a[0]] == n/3 && mp[a[n/3]] == n/3 && mp[a[n/3*2]] == n/3) {
      if((a[0] ^ a[n/3] ^ a[n/3*2]) == 0) {
        // cout << a[0] << a[n/3] << a[n/3*2];
        cout << "Yes\n"; return 0;
      }
    }
  }

  cout << "No\n";
  return 0;
}