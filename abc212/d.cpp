# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint mod=1000000007;
lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

lint inv(lint x) {
  lint res=1, k=mod-2;
  while(k>0) {
    if(k&1 == 1) res=(res*x)%mod;
    x=(x*x)%mod;
    k/=2;
  }
  return res;
}

lint nCr_mod(lint n, lint k) {
  lint a=1,b=1;
  for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  for(int i=0;i<k;i++) b=(b*(k-i))%mod;
  return (a*inv(b))%mod;
}

int main() {
  lint q,p,x; cin>>q;

  lint add=0;
  map<lint,lint> mp;
  rep(i,q) {
    cin>>p;

    if(p == 1) {
      cin>>x;
      mp[x-add]++;
    } else if(p == 2) {
      cin>>x;
      add+=x;

      /*
      map<lint,lint> mpsub;
      for(auto itr:mp) {
        mpsub[itr.first+x] = itr.second;
      }
      mp=mpsub;
      */
    } else {
      for(auto itr:mp) {
        if(itr.second > 0) {
          printf("%lld\n", itr.first+add);
          mp[itr.first]--;

          if(mp[itr.first] == 0) {
            mp.erase(itr.first);
          }

          break;
        }
      }
    }

  }

  return 0;
}
