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

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { 
        int rx = root(x); 
        int ry = root(y); 
        if (rx == ry) return; 
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
  lint t,l,x,y,q; cin>>t>>l>>x>>y>>q;
  double r=(double)l/2;

  vector<double> v0(3,0);
  v0[0] = (double)(-x);
  v0[1] = (double)(-y);

  double pi=acos(-1);
  lint e;
  rep(i,q) {
    vector<double> v1(3,0), v2(3,0), v3(3,0);
    cin>>e;

    v1[1] = -r*sin(2*pi*(double)e/t);
    v1[2] = r-r*cos(2*pi*(double)e/t);

    v2[0]=v0[0]+v1[0];
    v2[1]=v0[1]+v1[1];
    v2[2]=v0[2]+v1[2];

    v3=v2;
    v3[2]=0;

    // double in_cross=v0[0]*v2[0]+v0[1]*v2[1]+v0[2]*v2[2];
    // double norm0=sqrt(v0[0]*v0[0]+v0[1]*v0[1]+v0[2]*v0[2]);
    double norm2=sqrt(v2[0]*v2[0]+v2[1]*v2[1]+v2[2]*v2[2]);
    double in_cross=v3[0]*v2[0]+v3[1]*v2[1]+v3[2]*v2[2];
    // double norm0=sqrt(v0[0]*v0[0]+v0[1]*v0[1]+v0[2]*v0[2]);
    double norm3=sqrt(v3[0]*v3[0]+v3[1]*v3[1]+v3[2]*v3[2]);

    // printf("%.9lf\n", in_cross/norm2/norm3 );
    //  printf("%lf %lf %lf\n", in_cross, norm2, norm3);

    // printf("%.12lf\n", acos(in_cross/norm2/norm3)*180/pi );
    printf("%.12lf\n", atan(v1[2]/norm3)*180/pi );
    // printf("%lf %.12lf %.12lf %.12lf\n", norm2, v2[0], v2[1], v2[2]);
    // printf("%lf %.12lf %.12lf %.12lf\n", norm0, v0[0], v0[1], v0[2]);
    // printf("%.12lf %.12lf %.12lf\n", v1[0], v1[1], v1[2]);
  }

  return 0;
}
