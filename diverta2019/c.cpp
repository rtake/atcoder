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
  int n; cin >> n;
  vector<string> s(n); for(int i=0;i<n;i++) { cin >> s[i]; }

  int cnt_a=0, cnt_b=0, cnt0=0, ans=0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<(int)s[i].size()-1;j++) {
      if(s[i][j]=='A' && s[i][j+1]=='B') { ans++; }
    }
    if(s[i][0] == 'B') { cnt_b++; }
    if(s[i][(int)s[i].size()-1] == 'A') { cnt_a++; }
    if(s[i][0] == 'B' && s[i][(int)s[i].size()-1] == 'A') { cnt0++; }
  }

  if(cnt0>0 && (cnt_a-cnt0)+(cnt_b-cnt0)==0) { ans--; }
  cout << ans + cnt0 + min(cnt_a-cnt0,cnt_b-cnt0) << endl;
  return 0;
}
