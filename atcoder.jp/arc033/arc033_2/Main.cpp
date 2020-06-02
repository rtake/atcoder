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
  int na,nb; cin >> na >> nb;
  vector<lint> a(na), b(nb);
  for(lint i=0;i<na;i++) { cin >> a[i]; }
  for(lint i=0;i<nb;i++) { cin >> b[i]; }

  map<lint,lint> mp;
  for(lint i=0;i<na;i++) { mp[a[i]]++; }
  for(lint i=0;i<nb;i++) { mp[b[i]]++; }

  lint inter=0,sum=0;
  for(map<lint,lint>::iterator itr=mp.begin();itr!=mp.end();itr++) {
    if(itr->second == 1) { sum++; }
    else if(itr->second == 2) { inter++; sum++; }
  }

  printf("%.10lf\n",(double)inter/(double)sum);
  return 0;
}