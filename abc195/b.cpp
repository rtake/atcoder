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
  int a,b,w; cin >> a >> b >> w;
  w *= 1000;

  int cur=1, ans[2]={9999999,-9999999};
  while(true) {
    if(cur*a <= w && w <= cur*b) {
      ans[0] = min(ans[0],cur);
      ans[1] = max(ans[1],cur);
    } else if(w < cur*a && w < cur*b) { break; } 
    cur++;
  }

  if(ans[1] < 0) printf("UNSATISFIABLE\n");
  else printf("%d %d\n", ans[0], ans[1]);
 
  return 0;
}
