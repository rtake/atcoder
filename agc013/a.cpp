# include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<long long int> a(n,0),b(n,0); for(int i = 0;i < n;i++) { cin >> a[i]; }
  for(int i = 1;i < n;i++) { b[i] = a[i] - a[i-1]; }

  long long int ans=1;
  int flag = 0;

  for(int i = 1;i < n;i++) {
    if(flag == 0 && b[i] != 0) {
      if(b[i] < 0) { flag = -1; }
      else if(b[i] > 0) { flag = 1; }
    } else {
      if(flag*b[i] < 0) {
        if(flag > 0) { flag = 0; }
        else if(flag < 0) { flag = 0; }
        ans++;
      } 
    }
  }

  cout << ans << endl;
  return 0;
}
