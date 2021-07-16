# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint mod=1000000007;
lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }
lint P_mod(lint n, lint k) { return (k==1) ? n%mod : n*(P_mod(n-1,k-1))%mod; }

lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%1000000007;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
}


int main() {
  lint n; cin>>n;
  vector<lint> t(n); for(lint i=0;i<n;i++) cin>>t[i];

  lint sum=0, cnt=1;
  vector<lint> a(n,0);

  sort(t.begin(), t.end());
  a[0] = t[0];
  for(lint i=1;i<n;i++) a[i] = a[i-1]+t[i];
  for(lint i=0;i<n;i++) sum += a[i];

  map<lint,lint> mp;
  for(auto x:t) mp[x]++;
  for(auto x:mp) cnt = cnt*P_mod(x.second,x.second)%mod;

  printf("%lld\n%lld\n", sum, cnt%mod);
  return 0;
}