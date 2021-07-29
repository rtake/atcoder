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
  int n; cin>>n;
  vector<int> d(n); for(int i=0;i<n;i++) cin>>d[i];

  int dmax=0, dmin;
  for(int i=0;i<n;i++) dmax += d[i];

  int sum=0;
  sort(d.begin(), d.end());
  for(int i=0;i<n;i++) sum += d[i];

  if(sum-d[n-1] < d[n-1]) dmin = d[n-1]-(sum-d[n-1]);
  else dmin=0;

  printf("%d\n%d\n", dmax, dmin);
  return 0;
}
