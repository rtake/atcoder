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
  int n; cin >> n;
  vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];

  int cnt=0;
  vector<int> b(8,0);
  for(auto x:a) {
    if(x<3200) b[x/400]=1;
    else cnt++;
  }

  int sum=0;
  for(int i=0;i<8;i++) sum+=b[i];

  printf("%d %d\n", max(sum,1),sum+cnt);

  return 0;
}
