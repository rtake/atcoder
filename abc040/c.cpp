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


int dp(int n, int* memo, bool* in_memo, int* a) {
  if(!in_memo[n]) {
    memo[n] = \
      min(dp(n-2, memo, in_memo, a)+abs(a[n]-a[n-2]), dp(n-1, memo, in_memo, a)+abs(a[n]-a[n-1]));
    in_memo[n] = true;
  }

  return memo[n];
}


int main() {
  int n;
  scanf("%d\n", &n);
  int a[n+1];
  for(int i=1;i<=n;i++) { scanf("%d ", &a[i]); }

  int memo[n+1];
  bool in_memo[n+1];
  for(int i=1;i<=n;i++) { in_memo[i] = false; }

  in_memo[1] = true;
  in_memo[2] = true;
  memo[1] = 0;
  memo[2] = abs(a[1]-a[2]);

  printf("%d\n", dp(n, memo, in_memo, a));
  return 0;
}
