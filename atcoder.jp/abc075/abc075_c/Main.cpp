# include <bits/stdc++.h>
//# include <atcoder/all>

typedef long long lint;

using namespace std;
//using namespace atcoder;

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

// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }

int main() {
  int n,m; cin>>n>>m;
  vector<int> a(m),b(m);
  rep(i,m) {
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
  }

  vector< vector<int> > G(n, vector<int>(n,0));
  rep(i,m) G[a[i]][b[i]] = G[b[i]][a[i]] = 1;

  int ans=0;
  bool is_connected=false;
  rep(i,m) {
    is_connected=true;
    G[a[i]][b[i]] = G[b[i]][a[i]] = 0;

    vector<bool> is_arrived(n,false);
    deque<int> dq;

    dq.push_back(0);
    while(!dq.empty()) {
      int cur=dq.front();
      is_arrived[cur] = true;
      dq.pop_front();

      rep(j,n) {
        if(is_arrived[j] == false) {
          if(G[cur][j] == 1 || G[j][cur] == 1) {
            dq.push_back(j);
            // cout<<j<<endl;
          }
        }
      }
    }

    for(auto x:is_arrived) is_connected &= x;

    if(!is_connected) ans++;
    G[a[i]][b[i]] = G[b[i]][a[i]] = 1;
  }

  cout<<ans<<endl;

  return 0;
}