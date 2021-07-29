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
  int n,k; cin>>n>>k;
  vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];

  int l=0, r=0, ans=0;
  while(l<n && r<n) {
    while(a[r]<a[r+1]) {
      r++;
      if(r+1 >= n) break;
    }
    ans += max((r-l+1)-k+1,0);
    r++;
    l=r; // cout<<ans<<endl;
  }

  cout << ans << endl;
  return 0;
}
