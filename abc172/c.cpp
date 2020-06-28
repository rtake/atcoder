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
  lint n,m,k; cin >> n >> m >> k;
  vector<lint> a(n); for(lint i=0;i<n;i++) { cin >> a[i]; }
  vector<lint> b(m); for(lint i=0;i<m;i++) { cin >> b[i]; }
  
  lint cnt_a=0, sum=0, cnt_b=0, ans;
  for(cnt_a=0;cnt_a<n;cnt_a++) {
    if(sum+a[cnt_a]>k) { break; }
    sum += a[cnt_a];
  }

  for(cnt_b=0;cnt_b<m;cnt_b++) {
    if(sum+b[cnt_b]>k) { break; }
    sum += b[cnt_b];
  }

  ans = cnt_a + cnt_b;
  while(cnt_a>=0) {
    sum -= a[--cnt_a]; // remove last book of a
    while(sum<k) {
      if(cnt_b>=m) { break; }
      if(sum+b[cnt_b]>k) { break; }
      sum += b[cnt_b];
      cnt_b++;
    } // add new book from b
    ans = max(ans,cnt_a+cnt_b);
  }

  cout << ans << endl;
  return 0;
}
