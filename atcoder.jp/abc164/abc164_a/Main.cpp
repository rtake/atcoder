# include <iostream>
using namespace std;

int main() {
  int s, w; cin >> s >> w;
  if(w >= s) { cout << "unsafe\n"; } 
  else { cout << "safe\n"; }
  return 0;
}