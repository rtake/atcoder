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
  string s; cin>>s;
  stringstream ss(s);

  int y,m,d;
  string buf;
  getline(ss, buf, '/'); y=stoi(buf);
  getline(ss, buf, '/'); m=stoi(buf);
  getline(ss, buf, '/'); d=stoi(buf);

  int calendar[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

  int leap=0;
  if(m == 2) {
    if(y%4 == 0 && y%100 != 0 || y%400 == 0) leap=1;
  }

  for(int d0=d;d0<=calendar[m]+leap;d0++) {
    if(y%m == 0) {
      if(y/m%d0 == 0) {
        printf("%d/%02d/%02d\n", y, m, d0);
        return 0;
      }
    }
  }


  for(int m0=m+1;m0<=12;m0++) {
    if(m0 == 2) {
      if(y%4 == 0 && y%100 != 0 || y%400 == 0) leap=1;
    } else leap=0;

    for(int d0=1;d0<=calendar[m0]+leap;d0++) {
      if(y%m0 == 0) {
        if(y/m0%d0 == 0) {
          printf("%d/%02d/%02d\n", y, m0, d0);
          return 0;
        }
      }
    }

  }

  printf("%d/01/01\n", y+1);
  return 0;
}
