# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  string c; //fgets(c,2020,stdin);
  getline(cin,c); cout << c << endl;

  vector<char> vc;

  for(int i=0;i<2020;i++) {
    if(c[i] == ' ') {
      for(;i<2020;i++) {
        if(c[i] != ' ') {
          i--;
          break;
        }
      }
      vc.push_back(',');
    } else {
      vc.push_back(c[i]);
    }
  }

  for(int i=0;i<(int)vc.size();i++) { cout << vc[i]; }
  cout << endl;
  return 0;
}
