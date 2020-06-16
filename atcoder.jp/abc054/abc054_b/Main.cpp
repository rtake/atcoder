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
  string s;
  vector<string> a; for(int i=0;i<n;i++) { cin >> s; a.push_back(s); }
  vector<string> b; for(int i=0;i<m;i++) { cin >> s; b.push_back(s); }

  for(int i=0;i+m<=n;i++) {
    for(int j=0;j+m<=n;j++) {
      int chk=1;
      for(int k=0;k<m;k++) {
        if(a[j+k].substr(i,m) != b[k]) {
          chk *= 0;
          break;
        }  
      }
      
      if(chk == 1) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
