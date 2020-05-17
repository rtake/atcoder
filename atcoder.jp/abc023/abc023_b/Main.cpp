# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  int n; cin >> n;
  string s; cin >> s;

  int l=0, r=n-1, k=(n-1)/2;

  if( (n-1)%2 != 0 ) {
    cout << "-1\n";
    return 0;
  }

  for(int i=k;i>=0;i--) {
    if(i == 0) {
      if(s[l] == 'b') { break; }
      else {
        cout << "-1\n";
        return 0;
      }
    }

    if(i%3 == 0) {
      if(s[l] == 'b' && s[r] == 'b') {
        l++;
        r--;
      } else {
        cout << "-1\n";
        return 0;
      }
    } else if(i%3 == 1) {
      if(s[l] == 'a' && s[r] == 'c') {
        l++;
        r--;
      } else {
        cout << "-1\n";
        return 0;
      }
    } else if(i%3 == 2) {
      if(s[l] == 'c' && s[r] == 'a') {
        l++;
        r--;
      } else {
        cout << "-1\n";
        return 0;
      }
    }
  }

  cout << k << endl;
  return 0;
}
