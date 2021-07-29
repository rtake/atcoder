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
  int n; cin>>n;
  vector<int> a(n),b(n),c(n),d(n);
  rep(i,n) cin>>a[i]>>b[i];
  rep(i,n) cin>>c[i]>>d[i];

  vector< pair<int,int> > p,q;
  rep(i,n) p.emplace_back(a[i],b[i]);
  rep(i,n) q.emplace_back(c[i],d[i]);

  sort(p.begin(), p.end());
  sort(q.begin(), q.end());

  lint ans=0;
  for(auto itr_q:q) {
    vector< pair<int,int> > r;

    rep(i,n) {
      if(itr_q.first > p[i].first) r.emplace_back(itr_q.second,i);
      else break;
    }

    sort(r.begin(), r.end(), greater< pair<int,int> >());

    if((int)r.size() == 0) continue;
    else {
      p.erase(p.begin()+r[0].second);
      ans++;
    }
  }

  cout<<ans<<endl;
  return 0;
}
