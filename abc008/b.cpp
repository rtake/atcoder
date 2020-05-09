# include <bits/stdc++.h>
using namespace std;

int main() {
  int n, check, index; cin >> n;
  vector<string> svec(1);
  string s;
  vector<int> ivec(1,1);

  cin >> svec[0];
  for(int i = 1;i < n;i++) {
    cin >> s;
  
    check = -1;
    for(int j = 0;j < (int)svec.size();j++) {
      if(s == svec[j]) {
        ivec[j]++;
        check = 1;
        break;
      }
    }

    if(check == -1) {
      svec.push_back(s);
      ivec.push_back(1);
    }
  }

  index = 0;
  for(int i = 0;i < (int)ivec.size();i++) {
    if(ivec[index] < ivec[i]) { index = i; }
  }

  cout << svec[index] << endl;

  return 0;
}
