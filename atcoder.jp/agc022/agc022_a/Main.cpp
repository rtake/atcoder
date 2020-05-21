# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  string s; cin >> s;
  int size=(int)s.size();

  vector<int> v0(26,0),v1,v2;

  for(int i=0;i<size;i++) { v1.push_back(s[i]-'a'); }

  if(size < 26) {
    for(int i=0;i<size;i++) { v0[s[i]-'a'] = 1; }
    for(int i=0;i<26;i++) { if(v0[i] == 0) { v2.push_back(i); } }
    sort(v2.begin(),v2.end());
    v1.push_back(v2[0]);

    for(int i=0;i<(int)v1.size();i++) { printf("%c",v1[i]+'a'); }
    cout << endl;
    return 0;
  } else {
    for(int i=size-1;i>0;i--) {
      //if(i == 0) { cout << "-1\n"; return 0; }

      v2.push_back(v1[i]); v1.pop_back();
      sort(v2.begin(),v2.end());

      for(int j=0;j<(int)v2.size();j++) {
        if(v2[j] > v1[i-1]) {
          v1[i-1] = v2[j];
          for(int i=0;i<(int)v1.size();i++) { printf("%c",v1[i]+'a'); }
          cout << endl;
          return 0;
        }
      }
    }
  }

  cout << "-1\n";
  /*
  for(int i=0;i<(int)v1.size();i++) { printf("%c",v1[i]+'a'); }
  cout << endl;
  */
  return 0;
}