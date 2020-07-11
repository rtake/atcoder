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

int f(int x,int y,int z) { return x*x+y*y+z*z+x*y+y*z+z*x; }

int main() {
  int n; cin >> n;

  for(int i=1;i<=n;i++) {
    int a=0,b=0,c=0;

    for(int x=1;f(x,x,x)<=i;x++) {
      for(int y=x;f(x,x,y)<=i;y++) {
        for(int z=y;f(x,y,z)<=i;z++) {
          if( f(x,y,z)==i ) {
            if(x==y && y==z && z==x) { a++; }
            else if(x!=y && y!=z && z!=x) { c++; }
            else { b++; }
          }
        }
      }
    }

    printf("%d\n",a+3*b+6*c);
  }

  return 0;
}
