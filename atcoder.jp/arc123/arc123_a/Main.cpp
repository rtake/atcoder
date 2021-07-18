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
  lint a1,a2,a3; cin>>a1>>a2>>a3;

  lint k=a3-a2, l=a2-a1, ans;
  if(k-l>0) {
    if((k-l)%2 == 0) ans=(k-l)/2;
    else ans=(k-l+1)/2+1;
  } else {
    if((l-k)%2 == 0) ans=(l-k);
    else ans=(l-k);
  }

  printf("%lld\n", ans);
  return 0;
}