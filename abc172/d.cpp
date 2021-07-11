# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%1000000007;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
}


vector<lint> dp(10000001,0);
vector<bool> memo(10000001,false);

lint f(lint k) {
  if(memo[k]) return dp[k];

  dp[k] = 2;
  memo[k] = true;
  for(int i=2;i*i<=k;i++) {
    if(k%i == 0) {
      if(k/i == i) dp[k] = 2*f(k/i)-1;
      else dp[k] = 2*f(k/i);
      break;
    }
  }

  return dp[k];
}

int main() {
  lint n; cin >> n;
  // dp=vector<lint>(n+1,0);
  // memo=vector<bool>(n+1,false);

  lint ans=0;
  dp[1] = 1;
  memo[1] = true;
  for(lint k=n;k>=1;k--) { ans += k*f(k); cout << k << endl; }
  // for(lint k=n;k>=1;k--) ans += k*f(k);

  printf("%lld\n", ans);
  return 0;
}
