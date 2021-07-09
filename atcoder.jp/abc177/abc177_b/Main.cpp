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
  string s,t; cin >> s >> t;
  int ls=s.size(), lt=t.size();

  int ans=lt;
  for(int i=0;i+lt-1<ls;i++) {
    string sub=s.substr(i,lt);

    int cnt=0;
    for(int j=0;j<lt;j++) {
      if(sub[j] != t[j]) cnt++;
    }

    ans=min(ans,cnt);
  }

  cout << ans << endl;
  return 0;
}