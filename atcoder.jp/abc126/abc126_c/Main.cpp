# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n,k; cin >> n >> k;
  double p=0;

  for(int i=1;i<=n;i++) {
    double p0 = 1/((double)n);
    int score=i;

    while(score<k) {
      score *= 2;
      p0 /= 2;
    }

    p += p0;
  }

  printf("%.10lf\n",p);
  return 0;
}