# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

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
  lint a,b; cin>>a>>b;
  lint c=gcd(a,b);
  lint lim=c, cnt=1;

  for(lint i=2;i*i<=lim;i++) {
    if(c%i == 0) {
      while(c%i == 0) c/=i;
      cnt++;
    }
  }

  if(c>1) cnt++;

  printf("%lld\n", cnt);
  return 0;
}