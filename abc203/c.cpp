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
  vector<lint> a(n,0),b(n,0);
  for(lint i=0;i<n;i++) { cin >> a[i] >> b[i]; }

  // map<lint,lint> mp;
  // for(lint i=0;i<n;i++) { mp[a[i]] = b[i]; }

  vector< pair<lint,lint> > vp;
  for(lint i=0;i<n;i++) { vp.push_back( pair<lint,lint>(a[i],b[i]) ); }
  // for(lint i=0;i<n;i++) { vp[i].first *= -1; }
  sort(vp.begin(), vp.end());
  // sort(vp.begin(), vp.end());
  // for(lint i=0;i<n;i++) { vp[i].first *= -1; }

  lint cur=0;
  for(auto x : vp) {

    if(k-(x.first-cur) < 0) {
      cout << cur+k << endl;
      return 0;
    }

    k -= (x.first-cur);
    k += x.second;
    cur = x.first;
  }

  cout << cur+k << endl;
  return 0;
}
