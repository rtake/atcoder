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
  string s; cin>>s;

  int cur=0, ans=0, cnt=0;
  string chokudai="chokudai";
  vector< vector<int> > check(s.length(), vector<int>(8,0));

  if(s[0] == 'c') check[0][0]=1;

  for(int i=1;i<(int)s.length();i++) {
    check[i][0] = check[i-1][0];

    if(s[i] == chokudai[0]) check[i][0]++;

    for(int j=1;j<8;j++) {
      check[i][j] = check[i-1][j];
      if(s[i] == chokudai[j]) {
        check[i][j] += check[i-1][j-1];
        check[i][j] %= mod;
      }
    }

    // for(auto x:check[i]) cout<<x;
    // cout<<endl;
  }

  cout<<check[s.length()-1][7]%mod<<endl;
  return 0;
}
