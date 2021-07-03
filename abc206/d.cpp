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
  vector<lint> a(n+1); for(lint i=1;i<=n;i++) { cin >> a[i]; }

  map<lint,lint> mp;
  for(lint i=1;i<=n;i++) mp[i] = i;

  lint l,r;
  if(n%2==0) {
    l=n/2;
    r=l+1;
  } else {
    l=n/2;
    r=l+2;
  }

  lint ans=0;
  while(1 <= l && r <= n) {
    // printf("a[l] %lld mp[a[l]] %lld a[r] %lld m[a[r]] %lld\n", a[l], mp[a[l]], a[r], mp[a[r]]);

    if(mp[a[l]] != mp[a[r]]) {
      lint r0=mp[a[r]]; // cout << r0 << endl;

      // printf("%lld --> %lld\n", mp[a[r]], mp[a[l]]);
      mp[a[r]] = mp[a[l]];
      for(auto x:mp) {
        if(x.second == r0) {
          // printf("  x.first %lld : %lld --> %lld\n", x.first, x.second, mp[a[l]]); 
          mp[x.first] = mp[a[l]];
        }
      }
      ans++;
    }

    l--;
    r++;
  }

  printf("%lld\n", ans);

  return 0;
}
