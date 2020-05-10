# include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m; cin >> n >> m;
  n %= 12;
  double angle_m = ( (double)m/60)*360, angle_n = ( (double)n/12 + (double)m/(60*12) )*360;

  if( abs(angle_n-angle_m) <= 180 ) { cout << abs(angle_n-angle_m) << endl; }
  else { cout << 360 - abs(angle_n-angle_m) << endl;}

  return 0;
}