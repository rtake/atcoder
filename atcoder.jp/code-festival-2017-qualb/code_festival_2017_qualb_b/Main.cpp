# include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n;
  vector<long long int> d(n,0); for(int i = 0;i < n;i++) { cin >> d[i]; }
  cin >> m;
  vector<long long int> t(m,0); for(int i = 0;i < m;i++) { cin >> t[i]; }

  map<long long int,int> M;
  for(int i = 0;i < n;i++) { M[d[i]]++; }
  for(int i = 0;i < m;i++) {
    if(M[t[i]] <= 0) {
      cout << "NO\n";
      return 0;
    } else {
      M[t[i]]--;
    }
  }

  cout << "YES\n";
  return 0;
}