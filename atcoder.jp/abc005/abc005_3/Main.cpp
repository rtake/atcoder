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
  int t,n; cin >> t >> n;
  vector<int> a(n); for(int i=0;i<n;i++) { cin >> a[i]; }
  int m; cin >> m;
  vector<int> b(m); for(int i=0;i<m;i++) { cin >> b[i]; }

  deque<int> takoyaki;
  int cnt_a=0, cnt_b=0;
  for(int i=1;i<=100;i++) {
    for(;cnt_a<n;cnt_a++) {
      if(i == a[cnt_a]) { takoyaki.push_back(i); }
      else { break; }
    } // push bacl all takoyaki at i

    for(;cnt_b<m;cnt_b++) {
      if(i == b[cnt_b]) {
        while(true) {
          if(takoyaki.empty()) {
            cout << "no" << endl;
            return 0;
          } // no takoyaki

          int oldest_takoyaki = takoyaki.front();
          takoyaki.pop_front();
          if(i <= oldest_takoyaki+t) { break; } // can serve takoyaki
        }
      } else { break; }
    }
  }

  cout << "yes" << endl;
  return 0;
}
