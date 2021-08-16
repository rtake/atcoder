# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint mod=1000000007;
lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

lint inv(lint x) {
  lint res=1, k=mod-2;
  while(k>0) {
    if(k&1 == 1) res=(res*x)%mod;
    x=(x*x)%mod;
    k/=2;
  }
  return res;
}

lint nCr_mod(lint n, lint k) {
  lint a=1,b=1;
  for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  for(int i=0;i<k;i++) b=(b*(k-i))%mod;
  return (a*inv(b))%mod;
}

int main() {
  lint n,x; cin>>n>>x;

  lint ans=0;
  for(lint i=n;i>=0;i--) {
    if(x == 1) {
      // ans=0;
      break;
    // } else if(x <= n) {
    //  break;
    } else if(x < 1+(pow(2,i+1)-3)+1) {
      x--;
    } else if(x == 1+(pow(2,i+1)-3)+1) {
      ans += pow(2,i)-1;
      ans++;
      break;
    } else if(x == pow(2,i+2)+3) {
      ans = pow(2,i+1)-1;
      break;
    } else {
      ans += pow(2,i)-1;
      ans++;
      x -= 1+(pow(2,i+1)-3)+1;
    } 

  }

  printf("%lld\n", ans);

  return 0;
}
