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

int main() {
  int n; cin>>n;
  vector< vector<int> > z(n, vector<int>(n,-1));
  rep(i,n) {
    int x,y,a;
    cin>>a;
    rep(j,a) {
      cin>>x>>y;
      z[i][x-1] = y;
    }
  }

  int ans=0;
  for(int bit=0;bit<(1<<n);bit++) {

    bool is_reasonable=true;
    rep(i,n) {
      rep(j,n) {
        if(bit&(1<<i)) {
          if(z[i][j] == 0 && (bit&(1<<j)) > 0) is_reasonable=false;
          else if(z[i][j] == 1 && (bit&(1<<j)) == 0) is_reasonable=false;
        }
      }
    }

    int cnt=0;
    if(is_reasonable) {
      rep(i,n) {
        if(bit&(1<<i)) {
          cnt++;
          // cout<<(bit&(1<<i))<<endl;
        }
      }
    }

    ans=max(ans,cnt);
  }

  printf("%d\n", ans);
  return 0;
}