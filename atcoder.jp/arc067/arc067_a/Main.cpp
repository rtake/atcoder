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

  map<lint,lint> mp;
  for(lint i=n;i>=2;i--) {
    lint cur=i;

    for(int j=2;j<=cur;j++) {
      while(cur%j == 0) {
        cur /= j;
        mp[j]++;
      }
    }

  }

  lint ans=1;
  for(auto itr: mp) { ans = (ans*(itr.second+1))%1000000007; }

  printf("%lld\n",ans);
  return 0;
}
