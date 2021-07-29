# include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n);i++)
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
  int n,m; cin>>n>>m;
  vector<int> a(m),b(m); rep(i,m) cin>>a[i]>>b[i];

  vector< vector<bool> > mat(n, vector<bool>(n,false));
  rep(i,m) {
    mat[a[i]-1][b[i]-1] = true;
    mat[b[i]-1][a[i]-1] = true;
  }

  vector<int> v;
  rep(i,n-1) v.push_back(i+1);

  int ans=0;
  do{
    bool acceptable_path=true;
    for(int i=0;i<n-1;i++) {
      if(mat[v[i]][v[i+1]]) continue;
      acceptable_path=false;
    }

    if(acceptable_path) ans++;
  }while(next_permutation(v.begin(), v.end()));

  cout<<ans<<endl;
  return 0;
}
