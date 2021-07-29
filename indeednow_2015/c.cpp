# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%1000000007;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
}


int main() {
  lint n,m; cin>>n>>m;
  vector<lint> a(n),b(n),c(n),w(n); rep(i,n) cin>>a[i]>>b[i]>>c[i]>>w[i];
  vector<lint> x(m),y(m),z(m); rep(i,m) cin>>x[i]>>y[i]>>z[i];

  vector< tuple<lint,lint,lint,lint> > tps;
  rep(i,n) tps.emplace_back(w[i], a[i], b[i], c[i]);

  sort(tps.begin(), tps.end(), greater<tuple<lint,lint,lint,lint>>());

  for(int i=0;i<m;i++) {
    int ans=0, cur=0;

    for(int j=0;j<n;j++) {
      auto tp=tps[j];

      if(x[i]>=get<1>(tp) && y[i]>=get<2>(tp) && z[i]>=get<3>(tp)) {
        ans=get<0>(tp);
        break;
      }
    }

    cout<<ans<<endl;
  }

  return 0;
}
