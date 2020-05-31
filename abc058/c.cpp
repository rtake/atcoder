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
  int n; cin >> n;

  map<char,int> mp;
  for(int i=0;i<n;i++) {
    map<char,int> mp0;
    string s; cin >> s;
    for(int j=0;j<(int)s.size();j++) { mp0[s[j]]++; }

    if(i == 0) { mp = mp0; }
    else { for(map<char,int>::iterator i=mp.begin();i!=mp.end();i++) { mp[i->first] = min(i->second,mp0[i->first]); } }
  }

  vector<char> vc;
  for(map<char,int>::iterator i=mp.begin();i!=mp.end();i++) {
    for(int j=0;j<i->second;j++) { vc.push_back(i->first); }
  }

  sort(vc.begin(),vc.end());

  for(int i=0;i<(int)vc.size();i++) { cout << vc[i]; }
  cout << endl;
  return 0;
}
