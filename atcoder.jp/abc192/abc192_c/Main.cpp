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
  lint n,k; cin >> n >> k;

  for(lint i=0;i<k;i++) {
    lint g_1, g_2, f;
    vector<char> v;
    stringstream ss; ss << n;

    for(int i=0;i<(int)ss.str().size();i++) v.push_back(ss.str()[i]);

    sort(v.begin(), v.end());
    g_2=stoi( string(v.begin(), v.end()) );
    sort(v.begin(), v.end(), greater<char>());
    g_1=stoi( string(v.begin(), v.end()) );
    n = g_1 - g_2;
  }

  printf("%lld\n", n);

  return 0;
}