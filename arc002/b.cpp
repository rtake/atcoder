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
  lint n; cin >> n;
  string c; cin >> c;

  map<string,lint> mp, mp_sub;
  for(int i=0;i<n-1;i++) { mp[c.substr(i,2)]++; }

  pair<string,lint> max_pair, max_pair_sub;
  for(map<string,lint>::iterator itr=mp.begin();itr!=mp.end();itr++) {
    if(itr->second > max_pair.second) { max_pair = *itr; }
  }

  for(int i=0;i<n-1;i++) {
    if(c.substr(i,2) == max_pair.first) { i++; }
    else { mp_sub[c.substr(i,2)]++; }
  }

  for(map<string,lint>::iterator itr=mp_sub.begin();itr!=mp_sub.end();itr++) {
    if(itr->second > max_pair_sub.second) { max_pair_sub = *itr; }
  }

  cout << n - max_pair.second - max_pair_sub.second << endl;
  //printf("%s %lld %s %lld\n",max_pair.first.c_str(),max_pair.second,max_pair_sub.first.c_str(),max_pair_sub.second);
  return 0;
}
