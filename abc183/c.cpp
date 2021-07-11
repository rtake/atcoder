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
  int n,k; cin >> n >> k;
  vector< vector<int> > t(n, vector<int>(n));
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) cin >> t[i][j];
  }

  vector<int> v;
  for(int i=2;i<=n;i++) v.push_back(i);

  int ans=0;
  do {
    int sum = t[0][v[0]-1];
    for(int i=1;i<n-1;i++) sum += t[v[i]-1][v[i-1]-1];
    if(sum+t[v[n-2]-1][0] == k) ans++;
  } while( next_permutation(v.begin(), v.end()) );

  printf("%d\n", ans);
  return 0;
}
