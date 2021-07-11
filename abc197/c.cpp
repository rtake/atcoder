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
  return n*(P(n-1,k-1));
}


std::vector<std::vector<long long>> comb(int n, int r) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}



int main() {
  int n; cin >> n;  
  vector<lint> a(n); for(int i=0;i<n;i++) cin >> a[i];

  lint ans=1<<30;
  for(int bit=0;bit<(1<<(n-1));bit++) {
    vector<lint> b(n,0);

    for(int i=0;i<n-1;i++) {
      if(bit & (1<<i)) b[i+1] = a[i] | a[i+1];
      else {
        b[i] = a[i];
        b[i+1] = a[i+1];
      }
    }

    for(int i=1;i<n;i++) b[i] ^= b[i-1];
    ans = min(ans, b[n-1]);
  }

  cout << ans << endl;
  return 0;
}
