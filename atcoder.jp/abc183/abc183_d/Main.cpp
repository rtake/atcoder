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
  lint n,w;
  scanf("%lld %lld\n", &n, &w);
  vector<lint> s(n), t(n), p(n), u(2*100000,0);
  for(lint i=0;i<n;i++) { scanf("%lld %lld %lld\n", &s[i], &t[i], &p[i]); }

  for(lint i=0;i<n;i++) {
    u[s[i]] += p[i];
    u[t[i]] -= p[i];
  }

  lint sum=0;
  for(lint i=0;i<2*100000;i++) {
    sum += u[i];

    if(sum > w) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  return 0;
}