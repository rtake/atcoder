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
  lint a0=2, b0=0, q=2, a,b;

  for(int i=0;i<k;i++) {
    a = q*a0+b0;
    b = a0;

    a0 = a;
    b0 = b;
    // printf("%lld %lld\n", a, b);
  }

  printf("%lld %lld\n", a, b);

  /*
  lint cnt=0;
  while(b != 0) {
    lint asub=a;
    a = b;
    b = asub%b;
    cnt++;
    printf("%lld %lld\n", a, b);
  }

  printf("%lld\n", cnt);
  */

  return 0;
}
