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
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k])%1000000007;
    }
  }
  return v;
}


uintmax_t combination(unsigned int n, unsigned int r) {
  if ( r * 2 > n ) r = n - r;
  uintmax_t dividend = 1;
  uintmax_t divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}


lint dp[2000][2000];

lint nCr(lint n, lint r)
{
       if(n==r) return dp[n][r] = 1;
       if(r==0) return dp[n][r] = 1;
       if(r==1) return dp[n][r] = n;
       if(dp[n][r]) return dp[n][r]%1000000007;
       dp[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
       return dp[n][r];
}


int main() {
  int mod=1000000007, s; cin >> s;

  int ans=0;
  for(int i=1;i<=s/3;i++) {
    ans += nCr(s-i*3+(i-1), i-1);
    // ans += comb(s%i+(i-1), i-1)[s%i+(i-1)][i-1];
    ans %= mod;
  }

  printf("%d\n", ans);
  return 0;
}