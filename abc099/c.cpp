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


int dp(int amount, int* memo, bool* in_memo, int N) {
  if(!in_memo[amount]) {
    int amount_6, amount_9, sub;

    for(sub=1;sub*6<=amount;sub*=6) {}
    amount_6 = amount-sub;

    for(sub=1;sub*9<=amount;sub*=9) {}
    amount_9 = amount-sub;

    memo[amount] = \
     min(dp(amount-1, memo, in_memo, N), min(dp(amount_6, memo, in_memo, N),dp(amount_9, memo, in_memo, N)))+1;
    in_memo[amount] = true;
  }

  return memo[amount];
}


int main() {
  int N;
  scanf("%d", &N);

  int memo[N+1];
  bool in_memo[N+1];
  memo[0] = 0; in_memo[0] = true;
  for(int i=1;i<=N;i++) {
    memo[i] = 999999;
    in_memo[i] = false;
  }

  /*
  for(int i=1;i<=N;i*=6) {
    memo[i] = 1;
  }
  */

  printf("%d\n", dp(N, memo, in_memo, N));

  return 0;
}
