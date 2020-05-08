# include <bits/stdc++.h>
using namespace std;

int main() {
  string s; getline(cin,s,'\n');
  stringstream ss(s);
  int n; cin >> n;
  vector<string> t(n);
  for(int i = 0;i < n;i++) { cin >> t[i]; }

  int size, check;
  string buf;
  vector<string> svec;
  while( getline(ss,buf,' ') ) { svec.push_back(buf); }

  for(int i = 0;i < n;i++) {

    size = (int)t[i].size();
    for(int j = 0;j < (int)svec.size();j++) {
      if(size != svec[j].size()) { continue; }

      check = 1;
      for(int k = 0;k < size;k++) {
        if(t[i][k] == '*') { continue; }
        else if(t[i][k] == svec[j][k]) { continue; }
        else { check = -1; break; }
      } // for each charactor

      if(check == -1) { continue; }
      for(int k = 0;k < size;k++) { svec[j][k] = '*'; }
    } // for each word

  } // for each screening string

  for(int j = 0;j < (int)svec.size();j++) { cout << svec[j] << " "; }
  cout << endl;
  return 0;
}