# include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint comb[2000][2000];
lint nCr(lint n, lint r);

class UnionFind {
public:
  vector<int> Parent;

  UnionFind(int N) { Parent = vector<int>(N, -1); }
  int root(int A) { return Parent[A]<0 ? A : Parent[A]=root(Parent[A]); }
  int size(int A) { return -Parent[root(A)]; }

  bool connect(int A, int B) {
      A = root(A); B = root(B);
      if (A == B) return false;
      if (size(A) < size(B)) swap(A, B);

      Parent[A] += Parent[B];
      Parent[B] = A;
      return true;
  }
};

int main() {
  int n,m; cin>>n>>m;

  int ans=0;
  vector<int> a(n,0);
  UnionFind uni(n);

  rep(i,m) {
    int u,v; cin>>u>>v;
    u--; v--;

    if(uni.root(u) == uni.root(v)) a[u]++;
    uni.connect(u,v);
  }

  rep(i,n) ans+=a[i];
  cout<<ans<<endl;
  return 0;
}


lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%1000000007;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
}
