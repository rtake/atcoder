# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

lint C(lint n, lint k) {
  if(n == k) { return 1; }
  else if(n < k) { return 0; }
  else if(k == 0) { return 1; }
  else if(k == 1) { return n; }
  else return C(n-1,k-1) + C(n-1,k);
}

lint P(lint n, lint k) {
  if(k == 1) { return n; }
  return (n*(P(n-1,k-1)%1000000007)%1000000007);
}


int main() {
  int n,m; cin >> n >> m;
  vector< vector<int> > s(m,vector<int>(n,0));

  for(int i=0;i<m;i++) {
    int k; cin >> k;
    for(int j=0;j<k;j++) {
      int l; cin >> l;
      s[i][l-1] = 1;
    }
  }

  vector<int> p(m); for(int i=0;i<m;i++) { cin >> p[i]; }

  lint cnt=0, ans=0;
  for(int bit=0;bit<(1<<n);bit++) {

    int check = 1;
    for(int i=0;i<m;i++) {

      lint sum=0;
      for(int j=0;j<n;j++) {
        if(bit & (1<<j)) { sum += s[i][j]; } // switch on
      } // for each switch

      if(sum%2 != p[i]) { check *= 0; }

    } // for each lamp

    ans += check;
  }

  cout << ans << endl;
  return 0;
}
