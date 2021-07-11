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
  string s; cin >> s;
  int l=(int)s.size();

  vector<int> lcnt(l,1), rcnt(l,1);

  // lcnt[0] = 1;
  for(int i=0;i+2<l;i++) {
    if(s[i] == 'R' && s[i+1] == 'R') {
      lcnt[i+2] += lcnt[i];
      lcnt[i] = 0;
    }
  }

  // rcnt[0] = 1;
  for(int i=l-1;i-2>=0;i--) {
    if(s[i] == 'L' && s[i-1] == 'L') {
      rcnt[i-2] += rcnt[i];
      rcnt[i] = 0;
    }
  }

  for(int i=0;i<l;i++) printf("%d ", lcnt[i]+rcnt[i]-1);
  cout << endl;
  return 0;
}
