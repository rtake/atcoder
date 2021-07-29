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
  int x0,y0; cin>>x0>>y0;
  int n; cin>>n;
  
  vector<int> x(n),y(n); for(int i=0;i<n;i++) cin>>x[i]>>y[i];
  for(int i=0;i<n;i++) {
    x[i]-=x0;
    y[i]-=y0;
  }

  double ans=999999999;
  for(int i=0;i<n;i++) {
    double vx=(x[(i+1)%n]-x[i]), vy=(y[(i+1)%n]-y[i]);
    double wx=-vy, wy=vx;
    double k=((double)x[i]*wx+(double)y[i]*wy)/(wx*wx+wy*wy);
    // cout<<(double)x[i]*wx+(double)y[i]*wy<<endl;
    // cout<<k<<endl;
    ans = min(ans, abs(k*sqrt(wx*wx+wy*wy)) );
  }

  printf("%.12lf\n", ans);
  return 0;
}
