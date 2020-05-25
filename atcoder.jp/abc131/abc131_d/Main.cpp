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


int main() {
  lint n; cin >> n;
  vector< pair<lint,lint> > p(n,pair<lint,lint>(0,0));
  for(lint i=0;i<n;i++) {
    lint a,b; cin >> a >> b;
    p[i].first = b; p[i].second = a;
  }

  sort(p.begin(),p.end());

  lint sum=0;
  for(lint i=0;i<n;i++) {
    sum += p[i].second;
    if(sum > p[i].first) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  return 0;
}