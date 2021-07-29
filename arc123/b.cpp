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
  lint n; cin>>n;
  vector<lint> a(n),b(n),c(n);
  for(lint i=0;i<n;i++) cin>>a[i];
  for(lint i=0;i<n;i++) cin>>b[i];
  for(lint i=0;i<n;i++) cin>>c[i];

  vector< pair<lint,char> > v(0);
  for(lint i=0;i<n;i++) {
    v.emplace_back(a[i],'a');
    v.emplace_back(b[i],'b');
    v.emplace_back(c[i],'c');
  }

  sort(v.begin(), v.end());

  lint ans=0;
  vector<lint> l(3*n,0), r(3*n,0);
  for(int i=1;i<3*n;i++) {
    l[i] = l[i-1];
    if(v[i-1].second == 'a') l[i]++;
    else if(v[i-1].second == 'b') l[i] = max((lint)0, l[i]-1);
  }

  for(int i=3*n-2;i>=0;i--) {
    r[i] = r[i+1];
    if(v[i+1].second == 'c') r[i]++;
    else if(v[i+1].second == 'b') r[i] = max((lint)0, r[i]-1);
  }

  for(int i=0;i<3*n;i++) {
    printf("%lld %lld\n", l[i], r[i]);
    if(l[i] > 0 && r[i] > 0) ans++;
  }

  /*
  for(int i=0;i<3*n;i++) {
    cur=v[i].second;
    if(cur != next) continue;
    if(next == 'c') {
      ans++;
      next='a';
    } else if(cur == 'b') {
      next='c';
    } else if(cur == 'a') {
      next='b';
    }
  }
  */

  printf("%lld\n", ans);
  return 0;
}
