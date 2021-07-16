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
  int n; cin>>n;
  vector<string> w(n); for(int i=0;i<n;i++) cin>>w[i];

  char lastword=w[0][w[0].length()-1];
  map<string,int> mp;
  mp[w[0]]++;

  for(int i=1;i<n;i++) {
    if(mp[w[i]] > 0 || lastword != w[i][0]) {
      if((i+1)%2 == 1) cout << "LOSE\n";
      else cout << "WIN\n";
      return 0;
    }

    lastword = w[i][w[i].length()-1];
    mp[w[i]]++;
  }

  cout << "DRAW\n";
  return 0;
}
