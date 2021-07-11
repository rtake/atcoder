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
  return n*(P(n-1,k-1));
}


std::vector<std::vector<long long>> comb(int n, int r) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}



int main() {
  int p[2], q[2];
  cin >> p[0] >> p[1];
  cin >> q[0] >> q[1];

  int c=q[0]-p[0], d=q[1]-p[1], ans=0;
  if(c==0 && d==0) ans=0;
  else if(p[0]+q[0]==p[1]+q[1] || c==d || abs(c)+abs(d) <= 3) ans=1;
  else {
    int e=abs(c-d);
    ans=min(e%2+2, (e+3-1)/3+1);
  }

  cout << ans << endl;
  return 0;
}
