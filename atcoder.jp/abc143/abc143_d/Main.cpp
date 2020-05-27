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


int main() {
  int n; cin >> n;
  vector<int> l(n); for(int i=0;i<n;i++) { cin >> l[i]; }

  lint ans=0;
  sort(l.begin(),l.end());
  for(int i=0;i+2<n;i++) {
    for(int j=i+1;j+1<n;j++) {
      for(int k=j+1;k<n;k++) {
        if(l[i]+l[j] > l[k]) { ans++; }
        else { break; }
      }
    }
  }

  cout << ans << endl;
  return 0;
}