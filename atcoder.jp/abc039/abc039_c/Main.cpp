# include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  vector<int> pos;
  int ans;

  for(int i = 0;i < 19;i++) {
    i = s.find("WWB",i);
    if(i >= 0) { pos.push_back(i); }
    else { break; }
  }

  if( pos[1] - pos[0] == 5 ) { ans = 11 - pos[0]; } // Si-Mi-Si
  else if( pos[1] - pos[0] == 7 ) { ans = 4 - pos[0]; } // Mi-Si-Mi

  if(ans == 0) { cout << "Do\n"; }
  else if(ans == 2) { cout << "Re\n"; }
  else if(ans == 4) { cout << "Mi\n"; }
  else if(ans == 5) { cout << "Fa\n"; }
  else if(ans == 7) { cout << "So\n"; }
  else if(ans == 9) { cout << "La\n"; }
  else if(ans == 11) { cout << "Si\n"; }
  return 0;
}