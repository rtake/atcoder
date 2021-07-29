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
  lint n; cin>>n;
  vector<lint> a(n); rep(i,n) cin>>a[i];

  lint l=0,r=min(a[0],a[n-1]);
  lint cur=(l+r)/2;
  vector<lint> ans;
  while(true) {
    vector<lint> b(n,0);

    b[0]=2*cur;
    for(int i=1;i<n;i++) b[i] = 2*(a[i-1]-b[i-1]/2);

    if(b[0]/2+b[n-1]/2 == a[n-1]) {
      ans=b;
      break;
    } else if(b[0]/2+b[n-1]/2 > a[n-1]) {
      r=cur;
    } else {
      l=cur;
    }
    cur=(l+r)/2; cout<<cur<<endl;
  }

  for(auto x:ans) printf("%lld ", x*2);
  cout<<endl;
  return 0;
}
