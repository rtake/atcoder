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
  int h,w,k; cin >> h >> w >> k;
  vector<string> c(h); for(int i=0;i<h;i++) { cin >> c[i]; }
  // for(int i=0;i<h;i++) { cout << c[i] << endl; }

  vector<int> row(h,0), col(w,0); // count nuumber of '#'
  int cnt=0; // total number of '#'
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if(c[i][j] == '#') { row[i]++; }
    }
    cnt += row[i];
  } // count row

  for(int i=0;i<w;i++) {
    for(int j=0;j<h;j++) {
      if(c[j][i] == '#') { col[i]++; }
    }
  } // count col

  int ans=0;
  for(int bit_i=0;bit_i<(1<<h);bit_i++) {
    for(int bit_j=0;bit_j<(1<<w);bit_j++) {

      int chk=0;
      for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
          if((bit_i&(1<<i)) || (bit_j&(1<<j))) {
            if(c[i][j]=='#') {
              chk++;
            }
          } 
        }
      }

      if(chk == cnt-k) { ans++; }
    }
  }   

  cout << ans << endl;
  return 0;
}
