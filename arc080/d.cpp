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
  int h,w,n; cin >> h >> w >> n;
  vector<int> a(n); for(int i=0;i<n;i++) { cin >> a[i]; }
  
  int b[h][w], flag=1, pos_h=0, pos_w=0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<a[i];j++) {
      if(flag>0) {
        b[pos_h][pos_w++] = (i+1);
        if(pos_w>=w) {
          flag=-1;
          pos_h++;
          pos_w--;
        }
      } else {
        b[pos_h][pos_w--] = (i+1);
        if(pos_w<0) {
          flag=1;
          pos_h++;
          pos_w++;
        }
      }
    }
  }  

  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) { cout << b[i][j] << " "; }
    cout << endl;
  }
  return 0;
}
 