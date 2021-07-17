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


int main() {
  lint n,k; cin>>n>>k;
  vector<lint> x(n); for(lint i=0;i<n;i++) cin>>x[i];

  lint sum=0, ans;
  for(lint i=1;i<k;i++) sum += x[i]-x[i-1];
  ans = sum + min(abs(x[k-1]), abs(x[0]));

  for(lint i=1;i<=n-k;i++) { // cout << sum << endl;
    sum -= x[i]-x[i-1];
    sum += x[k+i-1]-x[k+i-2];

    ans = min(ans, sum+min(abs(x[i]), abs(x[k+i-1])));
  }

  printf("%lld\n", ans);
  return 0;
}