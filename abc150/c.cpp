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
  int n; cin>>n;
  vector<int> p(n),q(n);
  rep(i,n) cin>>p[i];
  rep(i,n) cin>>q[i];

  vector<int> r;
  rep(i,n) r.push_back(i+1);

  int cnt=0, a, b;
  do{
    if(r == p) a=cnt;
    if(r == q) b=cnt;
    cnt++;
  } while(next_permutation(r.begin(), r.end()));

  cout<<abs(a-b)<<endl;
  return 0;
}
