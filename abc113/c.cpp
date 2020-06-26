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
  lint n,m; cin >> n >> m;
  vector<lint> p(m), y(m); for(lint i=0;i<m;i++) { cin >> p[i] >> y[i]; }
  
  vector<lint> ymat[n];
  for(lint i=0;i<m;i++) { ymat[p[i]-1].push_back(y[i]); }
  for(lint i=0;i<n;i++) { sort(ymat[i].begin(),ymat[i].end()); } // sort for each prefucture

  vector< pair<lint,lint> > vp(m);
  for(lint i=0;i<m;i++) {
    vp[i].first = p[i];
    vp[i].second = (lint)(lower_bound(ymat[p[i]-1].begin(),ymat[p[i]-1].end(),y[i])-ymat[p[i]-1].begin()+1);
  }

  for(lint i=0;i<m;i++) { printf("%06lld%06lld\n",vp[i].first,vp[i].second); }
  return 0;
}