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


lint f(lint n) {
  stringstream ss;
  ss<<n;
  string s=ss.str();
  lint val=0;
  for(auto c:s) val += c-'0';
  return val;
}

int main() {
  lint n; cin>>n;

  vector<lint> v(0);
  for(lint i=1;i<=9*18 && i<=n;i++) {
    lint x=n-i;
    if(f(x) == i) v.push_back(x);
  }

  sort(v.begin(), v.end());

  printf("%lld\n", (lint)v.size());
  for(auto x:v) printf("%lld\n", x);

  return 0;
}
