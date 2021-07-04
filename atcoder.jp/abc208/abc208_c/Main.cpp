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
  lint n,k; cin >> n >> k;
  vector<lint> a(n); for(lint i=0;i<n;i++) cin >> a[i];

  lint cnt=0;
  cnt = k/n;
  k %= n;

  map<lint,lint> mp;
  for(auto x:a) mp[x] = cnt;

  for(auto itr=mp.begin();itr!=mp.end();itr++) {
    if(k <= 0) break;
    itr->second++; // cout << x.first << " " << x.second << endl;
    k--;
  }

  // for(auto x:mp) cout << x.first << " " << x.second << endl;
  for(lint i=0;i<n;i++) cout << mp[a[i]] << endl;

  return 0;
}