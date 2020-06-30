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
  vector<int> c(n),s(n),f(n); for(int i=0;i<n-1;i++) { cin >> c[i] >> s[i] >> f[i]; }

  int t=s[n-2], cnt=1;
  vector<int> a(n,0);

  a[n-2] = s[n-2]+c[n-2]; // the second last station
  cnt++;

  while(cnt<n) {
    int cur=n-2, t0 = t; // currnt station

    while(cur>0) {
      t0 -= c[cur-1];
      if(t0 < s[cur-1]) { break; }
      
      if((t0-s[cur-1])%f[cur-1] == 0) {
        a[cur-1] = t+c[n-2];// answear
        cnt++; // counting answear
      }
      cur--; // backward station
      // cout << cur << endl;
    }

    t += f[n-2];
    // cout << cnt << endl;
  } // for the last station

  for(int i=0;i<n;i++) { cout << a[i] << endl; }
  return 0;
}