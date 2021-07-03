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
  lint t,n; cin >> t >> n;

  lint cur, last, s=n/t;

  if(n%t == 0) {
    last = (100+t)*(s-1);

    for(lint i=(s-1)*100+1;i<=s*100;i++) {
      cur = (100+t)*i;
      cur /= 100;
      if(cur-last > 1) { break; }
      last = cur;
    }

  } else {
    lint cnt=s*t;
    last = (100+t)*s;

    for(lint i=s*100+1;i<=s*100+100;i++) {
      cur = (100+t)*i;
      cur /= 100;

      if(cur-last > 1) cnt++;
      if(cnt >= n) break;

      last = cur;
    }

  }

  printf("%lld\n", last+1);
  return 0;
}
