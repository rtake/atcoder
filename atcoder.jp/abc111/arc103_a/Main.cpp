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
  lint n; cin >> n;
  vector<lint> v(n); for(lint i=0;i<n;i++) { cin >> v[i]; }

  map<lint,lint> odd,evn;
  for(lint i=0;2*i<n;i++) { odd[v[2*i]]++; evn[v[2*i+1]]++; }

  lint ans=0;
  pair<lint,lint> oddpair_max0,oddpair_max1, evnpair_max0,evnpair_max1;
  for(map<lint,lint>::iterator itr=odd.begin();itr!=odd.end();itr++) {
    if(itr->second > oddpair_max1.second) {
      oddpair_max1 = *itr;
      if(oddpair_max1.second > oddpair_max0.second) { swap(oddpair_max0, oddpair_max1); }
    }
  }

  for(map<lint,lint>::iterator itr=evn.begin();itr!=evn.end();itr++) {
    if(itr->second > evnpair_max1.second) {
      evnpair_max1 = *itr;
      if(evnpair_max1.second > evnpair_max0.second) { swap(evnpair_max0, evnpair_max1); }
    }
  }

  if(oddpair_max0.first != evnpair_max0.first) { ans = n-oddpair_max0.second-evnpair_max0.second; }
  else { ans = n-max(oddpair_max0.second+evnpair_max1.second, oddpair_max1.second+evnpair_max0.second); }

  cout << ans << endl;
  return 0;
}
