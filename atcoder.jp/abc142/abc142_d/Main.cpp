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

  lint cnt=0;
  set<lint> st;

  st.insert(1);
  for(lint i=2;i*i<=a;i++) {
    if(a%i == 0) {
      st.insert(i);
      while(a%i == 0) a/=i;
    }
  }

  st.insert(a);

  for(auto x:st) {
    if(b%x == 0) cnt++;
  }

  printf("%lld\n", cnt);
  return 0;
}