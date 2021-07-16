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
  string s; cin>>s;

  map<char,int> mp;
  for(auto c:s) mp[c]++;

  vector<int> v(2,0);
  for(auto x:mp) {
    if(x.second%2 == 1) v[1]++;
    v[0] += x.second/2;
  }

  if(v[1] == 0) printf("%d\n", v[0]*2);
  else printf("%d\n", 1+v[0]/v[1]*2);
  return 0;
}