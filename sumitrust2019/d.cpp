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
  int n; cin >> n;
  string s; cin >> s;

  map<string,int> mp;
  vector<int> check(10,0);
  for(int i=0;i<n;i++) {
    string t = "   ";
    if(check[(int)s[i]-'0'] == 1) { continue; }
    t[0] = s[i];

    for(int j=i+1;j<n;j++) {
      if(s[j]!=s[i] && check[(int)s[j]-'0']==1) { continue; } 
      t[1] = s[j];

      for(int k=j+1;k<n;k++) {
        t[2] = s[k];      
        mp[t]++;
      } // third digit

      check[(int)s[j]-'0'] = 1;
    } // second digit

    check[(int)s[i]-'0'] = 1;
  } // first digit

  int ans=0;
  for(map<string,int>::iterator itr=mp.begin();itr!=mp.end();itr++) { ans += itr->second; }
 
  cout << ans << endl;
  return 0;
}