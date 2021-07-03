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
  vector<int> t(n),l(n),r(n); for(int i=0;i<n;i++) { cin >> t[i] >> l[i] >> r[i]; }

  vector< pair<pair<int,int>, int> > vpp(n);
  for(int i=0;i<n;i++) {
    vpp[i].second = t[i];
    vpp[i].first.first = l[i];
    vpp[i].first.second = r[i];
  }

  sort(vpp.begin(), vpp.end());
  // cout << vpp[0].first.first << endl;
  // cout << vpp[n-1].first.second << endl;

  lint ans=0;
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      if(vpp[i].first.second < vpp[j].first.first) {
        break;
      } else if(vpp[i].first.second == vpp[j].first.first) {
        if(vpp[i].second == 1 || vpp[i].second == 3) {
          if(vpp[j].second == 1 || vpp[j].second == 2) {
            ans++;
          }
        }
      } else if(vpp[i].first.second > vpp[j].first.first) {
        ans++;
      }
      
    }
  }

  printf("%lld\n", ans);
  return 0;
}
