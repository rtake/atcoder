# include <bits/stdc++.h>
using namespace std;

int main() {
  long long int x; cin >> x;

  for(int t = 1;;t++) {
    if(t*(t+1)/2 >= x) { cout << t << endl; return 0; }
  }

  return 0;
}