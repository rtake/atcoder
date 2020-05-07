# include <iostream>
# include <vector>
# include <string>
# include <set>

using namespace std;

int main() {
  int n; cin >> n;
  set<string> S;
  string s;
  
  for(int i = 1;i <= n;i++) { cin >> s; S.insert(s); }
  
  cout << S.size() << endl;
  //for(auto i : S) { cout << i << endl; }
  
  return 0;
}