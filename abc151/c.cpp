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
  int n,m; cin >> n >> m;
  vector<int> p(m);
  vector<string> s(m);
  for(int i=0;i<m;i++) cin >> p[i] >> s[i];

  int ac=0, penalty=0;
  vector<int> a(n+1,0);
  vector<bool> solved(n+1,false);
  for(int i=0;i<m;i++) {
    if(s[i] == "AC" && solved[p[i]] == false) {
      ac++;
      penalty += a[p[i]];
      solved[p[i]] = true;
    } else { a[p[i]]++; }
  }

  printf("%d %d\n", ac, penalty);
  return 0;
}