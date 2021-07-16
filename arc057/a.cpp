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
  lint a,k; cin>>a>>k;
  lint sum=2000000000000;

  lint n=0, t=a;
  if(k == 1) {
    for(n=1;t<sum;n++) {
      t += 1+t;
      if(t >= sum) break;
    }
  } else if(k == 0) {
    n = sum-a;
  } else {
    for(n=1;t<sum;n++) { 
      t += 1+k*t;
      if(t >= sum) break;
    }
  }

  printf("%lld\n", n);
  return 0;
}
