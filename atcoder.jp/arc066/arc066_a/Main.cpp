# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint mod=1000000007;
lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }
lint P_mod(lint n, lint k) { return (k==1) ? n%mod : n*(P_mod(n-1,k-1))%mod; }

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
  vector<lint> a(n); for(lint i=0;i<n;i++) cin>>a[i];

  map<lint,lint> mp;
  for(lint i=0;i<n;i++) mp[a[i]]++;

  lint ans=1;
  if(n%2 == 1) {
    if(mp[0] != 1 && mp[1] != 0) {
      cout << 0 << endl;
      return 0;
    }

    for(lint i=2;i<=n-1;i++) {
      if(i%2 == 0) {
        if(mp[i] != 2) {
          ans=0;
          break;
        } else ans = (ans*2)%mod;
      } else {
        if(mp[i] > 0) {
          ans=0;
          break;
        }
      }
    }
  } else {
    if(mp[0] != 0 && mp[1] != 2) {
      cout << 0 << endl;
      return 0;
    }

    ans=2;
    for(lint i=2;i<=n-1;i++) {
      if(i%2 == 1) {
        if(mp[i] != 2) {
          ans=0;
          break;
        } else ans = (ans*2)%mod;
      } else {
        if(mp[i] > 0) {
          ans=0;
          break;
        }
      }
    }
  }

  printf("%lld\n", ans%mod);
  return 0;
}