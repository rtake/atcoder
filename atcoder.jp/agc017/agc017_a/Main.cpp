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
  lint n,p; cin >> n >> p;
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }

  vector<lint> odd(n,0), evn(n,0);
  for(lint i=0;i<n;i++) {
    if(i == 0) {
      if(a[i]%2 == 0) { evn[i] = 2; odd[i] = 0; }
      else { evn[i] = 1; odd[i] = 1; }
    } else {
      if(a[i]%2 == 0) { evn[i] = evn[i-1]*2; odd[i] = odd[i-1]*2; }
      else { evn[i] = evn[i-1]+odd[i-1]; odd[i] = evn[i-1]+odd[i-1]; }
    }
  }

  if(p == 0) { cout << evn[n-1];}
  else { cout << odd[n-1]; }
  cout << endl;
  return 0;
}
