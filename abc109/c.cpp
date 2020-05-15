# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int gcd(int x, int y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

int lcm(int x, int y) { return abs(x,y)/gcd(x,y); }

int main() {
  lint N,X,y; cin >> N >> X;
  vector<lint> x(N,0);
  for(lint i=0;i < N;i++) { cin >> y; x[i] = abs(y-X); }

  int d=x[0];
  for(lint i=1;i<N && d!=1;i++) { d = gcd(x[i],d); }

  cout << d << endl;
  return 0;
}
