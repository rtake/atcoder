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
  lint n; cin >> n;

  vector<lint> a(n+1);
  int cnt=1;
  for(int i=1;i<=n;i*=2) a[i] = cnt++;
  for(int i=2;i<=n;i++) a[i] = max(a[i],a[i-1]);
  for(int i=1;i<=n;i++) printf("%lld ", a[i]);
  cout << endl;

  return 0;
}
