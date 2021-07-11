# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

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
  vector<lint> a(n+1),b(n+1);
  for(lint i=1;i<=n;i++) cin>>a[i];
  for(lint i=1;i<=n;i++) cin>>b[i];
  vector<lint> c(m),d(m);
  for(lint i=0;i<m;i++) cin>>c[i]>>d[i];

  vector< vector<lint> > G(n+1);
  for(lint i=0;i<m;i++) {
    G[c[i]].push_back(d[i]);
    G[d[i]].push_back(c[i]);
  }

  vector<bool> is_checked(n+1, false);
  for(lint i=1;i<=n;i++) {
    if(is_checked[i]) continue;

    vector<lint> path;
    deque<lint> dq;

    dq.push_back(i);
    while(!dq.empty()) {
      lint cur=dq.front();
      dq.pop_front();

      is_checked[cur] = true;
      path.push_back(cur);

      for(auto x:G[cur]) {
        if(!is_checked[x]) dq.push_back(x);
      }
    }

    lint sum=0;
    for(auto x:path) {
      // printf("%lld %lld - %lld\n", x, a[x], b[x]);
      sum += b[x]-a[x];
    }

    if(sum != 0) {
      cout << "No\n";
      return 0;
    }
  }
  
  cout << "Yes\n";
  return 0;
}
