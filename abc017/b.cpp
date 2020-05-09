# include <bits/stdc++.h>
using namespace std;

string x;

int dfs(int index) {
  int ret = -1;

  if(index == -1) { ret = 1; }
  else if(index == 1) {
    if(x[index-1] == 'c' && x[index] == 'h') { ret = 1; }
  } else if(index == 0) {
    if(x[index] == 'o' || x[index] == 'k' || x[index] == 'u') { ret = 1; }
  } else { 
    if(x[index-1] == 'c' && x[index] == 'h') { ret = dfs(index-2); }
    else if(x[index] == 'o' || x[index] == 'k' || x[index] == 'u') { ret = dfs(index-1); }
  }

  return ret;
}

int main() {
  cin >> x;
  int ans = dfs( (int)x.size() - 1 );

  if(ans == 1) { cout << "YES\n"; }
  else { cout << "NO\n"; }
  return 0;
}
