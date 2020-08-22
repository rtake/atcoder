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
  lint h,w; cin >> h >> w;
  lint c[2], d[2];
  cin >> c[0] >> c[1];
  cin >> d[0] >> d[1];
  
  vector<string> s(h); for(lint i=0;i<h;i++) { cin >> s[i]; }

  vector< vector<lint> > e(h, vector<lint>(w,1e+10)), check(h, vector<lint>(w,-1));
  deque< pair<lint,lint> > dq;

  e[c[0]-1][c[1]-1] = 0;
  check[c[0]-1][c[1]-1] = 0;
  dq.push_back( pair<lint,lint>(c[0],c[1]) );
  
  while(!dq.empty()) {
    pair<lint,lint> p = dq.front();
    dq.pop_front();

    printf("%lld, %lld\n", p.first, p.second);

    for(lint i=-1;i<=1;i++) {
      if(p.first-1+i < 0 || p.first-1+i > h) { continue; }

      for(lint j=-1;j<=1;j++) {
        if(p.second-1+j < 0 || p.second-1+j > w) { continue; }
        e[p.first-1+i][p.second-1+j] = min(e[p.first-1+i][p.second-1+j], e[p.first-1][p.second-1]);

        if(check[p.first-1+i][p.second-1+j] == -1) {
          check[p.first-1+i][p.second-1+j] = 1;
          dq.push_back( pair<lint,lint>(p.first+i, p.second+j) );
        }
      }
    }

    for(lint i=-2;i<=2;i++) {
      if(p.first-1+i < 0 || p.first-1+i > h) { continue; }

      for(lint j=-2;j<=2;j++) {
        if(p.second-1+j < 0 || p.second-1+j > w) { continue; }
        printf("(%lld, %lld), %lld, %lld\n", p.first, p.second, e[p.first-1+i][p.second-1+j], e[p.first-1][p.second-1]+1);
        e[p.first-1+i][p.second-1+j] = min(e[p.first-1+i][p.second-1+j], e[p.first-1][p.second-1]+1);

        if(check[p.first-1+i][p.second-1+j] == -1) {
          check[p.first-1+i][p.second-1+j] = 1;
          dq.push_back( pair<lint,lint>(p.first+i, p.second+j) );
        }
      }
    }


  }
  
  cout << e[d[0]-1][d[1]-1] << endl;
  return 0;
}
