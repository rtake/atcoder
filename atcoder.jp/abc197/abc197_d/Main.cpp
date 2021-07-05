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
  int n; cin >> n;
  int x,y;
  vector<double> a,b,c;
  cin >> x >> y; a.push_back((double)x); a.push_back((double)y);
  cin >> x >> y; b.push_back((double)x); b.push_back((double)y);

  for(int i=0;i<2;i++) c.push_back((b[i]-a[i])/2);
  double pi=acos(-1);
  double theta=pi*((double)n+2)/(double)n; // cout << (theta-pi)*n << endl;

  vector<double> d(2,0);
  d[0] = a[0] + c[0] + cos(theta)*c[0] - sin(theta)*c[1];
  d[1] = a[1] + c[1] + sin(theta)*c[0] + cos(theta)*c[1];

  // d[0] = a[0] + c[0];// + cos(theta)*c[0] - sin(theta)*c[1];
  // d[1] = a[1] + c[1];// + sin(theta)*c[0] + cos(theta)*c[1];
  printf("%.12lf %.12lf\n", d[0], d[1]);

  return 0;
}