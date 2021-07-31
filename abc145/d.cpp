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

int main() {
  lint x,y; cin>>x>>y;
  lint a=0,b=0;

  if((2*y-x)%3 == 0) { 
    a=(2*y-x)/3;
    b=(2*x-y)/3;
  } else {
    cout<<0<<endl;
    return 0;
  }

  if(a<0 || b<0) {
    cout<<0<<endl;
    return 0;
  }

  lint p=1,q=1,r=1,n=a+b;
  rep(i,n) p = (p*(n-i))%mod;
  rep(i,n-a) q = (q*(n-a-i))%mod;
  rep(i,a) r = (r*(a-i))%mod;

  lint qr=(q*r)%mod;
  // lint inv_qr=1, k=mod-2;
  // rep(i,mod-2) inv_qr = (inv_qr*qr)%mod;

  /*
  while(k) {
    if(k & 1) inv_qr = (inv_qr*qr)%mod;
    qr = (qr*qr)%mod;
    k/=2;
  }
  */

  // printf("%lld\n", (p*inv_qr)%mod);
  printf("%lld\n", (p*inv(qr))%mod);
  return 0;
}
