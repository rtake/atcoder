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
  lint n,k,m,r; cin >> n >> k >> m >> r;
  vector<lint> s(n,0); for(lint i=0;i<n-1;i++) { cin >> s[i]; }

  sort(s.begin(),s.end(),greater<lint>());
  lint sum=0;

  for(lint i=0;i<k;i++) { sum += s[i]; }
/*
  if(k == n) {
    lint x = n*r -sum;
    if(x>=m+1) { printf("-1\n"); }
    else if(x<=0) { printf("0\n"); }
    else { printf("lld\n",x); }
  }
*/
  if(sum >= k*r) { printf("0\n"); }
  else {
    lint x = k*r-(sum-s[k-1]);
    if(x > m) { printf("-1\n"); }
    else { printf("%lld\n",x); }
  }

  return 0;
}
