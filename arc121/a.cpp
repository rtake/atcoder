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

using std::abs;

int main() {
  int n; cin >> n;
  // vector< vector<int> > g(n, vector<int>(2,0));
  // for(int i=0;i<n;i++) { cin >> g[i][0] >> g[i][1]; }

  vector< pair<int,int> x(n), y(n); 
  for(int i=0;i<n;i++) { 
    cin >> x[i].first >> y[i].first;
    x[i].second = i;
    y[i].second = i;
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  int ans;
  if(x[0].second == y[0].second && x[n-1].second == y[n-1].second) {
    ans = min(abs(x[0].first-y[].first), abs());
  } else {

  }

  printf("%d\n", ans);
  return 0;
}
