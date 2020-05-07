# include <bits/stdc++.h>
using namespace std;

int main() { 
  string s,l,r; cin >> s;
  int size = s.size();
  
  if( s == "keyence") { cout << "YES\n"; return 0; }
  
  for(int i = 0;i < size;i++) {
    for(int j = i;j < size;j++) {
      l = s.substr(0,i);
      r = s.substr(j+1,size-1-j+1);
      if(l+r == "keyence") {
        cout << "YES\n";
        return 0;
      }
    }
  }
  
  cout << "NO\n";
  return 0;
}