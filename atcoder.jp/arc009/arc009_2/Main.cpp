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
  vector<int> b(10), c(10);
  for(int i=0;i<10;i++) { cin >> b[i]; c[b[i]] = i; }
  int n; cin >> n;
  vector<lint> a(n); for(int i=0;i<n;i++) { cin >> a[i]; }

  /*map<lint,lint> mp;
  for(int i=0;i<n;i++) {
    lint value=0, a_0=a[i], cur=10;
    while(a_0>0) {
      value += (cur/10)*c[a_0%cur-1];
      a_0 /= 10;
      cur *= 10;
    }
    mp[value] = a[i];
  }
  */

  vector< pair<lint,lint> > vp(n,pair<lint,lint>(0,0));
  for(int i=0;i<n;i++) {
    lint cur=10, value=0;
    vp[i].second = a[i];

    while(a[i]>0) {
      value += (cur/10)*c[a[i]%10];
      a[i] /= 10;
      cur *= 10;
    }
    vp[i].first = value;
  }

  sort(vp.begin(),vp.end());
  for(int i=0;i<n;i++) { cout << vp[i].second << endl; }

  // for(map<lint,lint>::iterator itr=mp.begin();itr!=mp.end();itr++) { cout << itr->second << endl; }
  return 0;
}
