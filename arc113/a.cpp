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
  lint k; cin>>k;

  lint ans=0;
  for(lint a=1;a*a*a<=k;a++) ans++;

  for(lint a=1;a*a<=k;a++) {
    for(lint b=1;a*a*b<=k;b++) {
      if(a != b) ans+=3;
    }
  }

  for(lint a=1;a<=k;a++) {
    for(lint b=a+1;a*b<=k;b++) {
      for(lint c=b+1;a*b*c<=k;c++) ans+=6;
    }
  }

  printf("%lld\n", ans);
  return 0;
}
