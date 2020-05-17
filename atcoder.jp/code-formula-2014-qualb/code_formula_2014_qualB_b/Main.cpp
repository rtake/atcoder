# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  string n; cin >> n;
  lint ev=0, od=0;

  reverse(n.begin(),n.end());
  for(int i=(int)n.size()-1;i>=0;i--) {
    if((i+1)%2 == 1) { od += n[i] - '0'; }
    if((i+1)%2 == 0) { ev += n[i] - '0'; }
  }

  cout << ev << " " << od << endl;
  return 0;
}