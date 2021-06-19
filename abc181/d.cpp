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
  string s; cin >> s;

  map<char,int> mp;
  for(int i=0;i<(int)s.size();i++) { mp[s[i]]++; }

  for(int i=0;i<1000;i+=8) {
    ostringstream oss; oss << i;
    int n=(int)oss.str().size();
    bool found=true;

    map<char,int> mp_i, mp0=mp;
    for(int j=0;j<n;j++) { mp_i[oss.str()[j]]++; }

    if(n < 3) {
      if(mp0 == mp_i) { found = true; }
      else if(mp0 != mp_i) { found = false; }
    } else {

      for(auto x : mp_i) {
        if(mp0[x.first] < x.second) {
          found = false;
        }
      }

    }

    if(found) {
      printf("Yes\n");
      return 0;
    }

  }

  printf("No\n");
  return 0;
}
