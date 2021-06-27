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
  int n,m; cin >> n >> m;
  vector<int> a(m), b(m); for(int i=0;i<m;i++) cin >> a[i] >> b[i];
  int k; cin >> k;
  vector<int> c(k) ,d(k); for(int i=0;i<k;i++) cin >> c[i] >> d[i];

  int ans=0;
  for(int bit=0;bit<(1<<k);bit++) {
    map<int,int> mp;

    for(int j=0;j<k;j++) {
      if(bit & (1<<j)) mp[c[j]]++;
      else mp[d[j]]++;
    }

    int test=0;
    for(int i=0;i<m;i++) {
      if(mp[a[i]] > 0 && mp[b[i]] > 0) test++;
    }

    ans = max(ans, test);
  }

  cout << ans << endl;
  return 0;
}