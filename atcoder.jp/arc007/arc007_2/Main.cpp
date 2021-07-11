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
  int n,m; cin>>n>>m;
  vector<int> disk(m,0); for(int i=0;i<m;i++) cin>>disk[i];

  map<int,int> mp;
  for(int i=0;i<=n;i++) mp[i] = i; // <position, disk>

  for(int i=0;i<m;i++) {
    for(auto x:mp) {
      if(x.second == disk[i]) {
        swap(mp[0], mp[x.first]);
        // mp[x.first] = mp[disk[0]];
        // mp[disk[0]] = x.second;
      }
    }
  }

  for(int i=1;i<=n;i++) cout << mp[i] << endl;

  return 0;
}