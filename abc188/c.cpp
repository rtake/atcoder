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
  lint n; cin >> n;
  lint m=pow(2,n);

  lint cur_val, l_pos=0, l_val=0, r_pos=m/2, r_val=0;
  for(lint i=0;i<m/2;i++) {
    cin >> cur_val;
    if(l_val < cur_val) {
      l_val = cur_val;
      l_pos = i;
    }
  }

  for(lint i=m/2;i<m;i++) {
    cin >> cur_val;
    if(r_val < cur_val) {
      r_val = cur_val;
      r_pos = i;
    }
  }

  if(l_val < r_val) printf("%lld\n", l_pos+1);
  else printf("%lld\n", r_pos+1);

  return 0;
}
