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

lint f(lint n) {
  lint ret=0;
  

  return ret;
}

int main() {
  lint n; cin >> n;
  
  vector<lint> c(n+1,0);
  c[0] = 1;
  c[n] = 1;
  for(lint i=2;i*i<=n;i++) {
    while(n%i != 0) {
      n /= i;
      c[i]++;
    }
  }

  lint ans=0;
  for(lint i=) {}
  cout << ans << endl;
  return 0;
}
