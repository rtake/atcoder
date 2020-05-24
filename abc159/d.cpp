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
  lint n; cin >> n;
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  lint sum=0;
  map<lint,lint> mp;
  for(lint i=0;i<n;i++) { mp[a[i]]++; }
  for(map<lint,lint>::iterator i=mp.begin();i!=mp.end();i++) { sum += i->second*(i->second-1)/2; }

  for(lint i=0;i<n;i++) { cout << sum-(mp[a[i]]-1) << endl; }

  return 0;
}
