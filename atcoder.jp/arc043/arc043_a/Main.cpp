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
  lint n,a,b; cin >> n >> a >> b;
  vector<lint> s(n); for(lint i=0;i<n;i++) { cin >> s[i]; }

  double p,q,average=0;
  lint s_min=1000000000, s_max=0LL;

  for(lint i=0;i<n;i++) {
    s_min = min(s_min,s[i]);
    s_max = max(s_max,s[i]);
    average += s[i];
  }
  average /= (double)n;

  if(s_min == s_max) {
    cout << -1 << endl;
    return 0;
  }

  p = (double)b/((double)(s_max-s_min));
  q = (double)a - p*(double)average;

  printf("%.10lf %.10lf\n",p,q);
  return 0;
}