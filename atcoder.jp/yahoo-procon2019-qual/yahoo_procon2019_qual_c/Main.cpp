# include <bits/stdc++.h>
using namespace std;

int main() {
  long long int ans,k,a,b; cin >> k >> a >> b;

  if(k-(a-1) <= 0) { cout << k+1 << endl; return 0; }

  if(b-a >= 2) {
    ans = a;
    ans += (b-a)*((k-(a-1))/2);
    ans += (k-(a-1)) %2;
  } else {
    ans = k+1;
  }

  cout << ans << endl;
  return 0;
}