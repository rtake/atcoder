# include <bits/stdc++.h>
using namespace std;

int main() { 
  int N,T; cin >> N >> T;
  vector<int> t(N,0); for(int i = 0;i < N;i++) { cin >> t[i]; }
  int total = T;

  for(int i = 1;i < N;i++) {
    if( t[i] - t[i-1] > T ) { total += T; }
    else { total += t[i] - t[i-1]; }
  }
  
  cout << total << endl;
  return 0;
}