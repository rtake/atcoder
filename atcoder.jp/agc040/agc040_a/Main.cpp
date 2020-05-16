# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  string s; cin >> s;
  lint n = (int)s.size()+1;
  vector<int> l(n,0), r(n,0);

  l[0]=0; r[n-1]=0;
  for(lint i=1;i<n;i++) {
    if(s[i-1]=='<') { l[i] = l[i-1]+1; }
    else if(s[i-1]=='>') { l[i] = 0; }
  }

  for(lint i=n-2;i>=0;i--) {
    if(s[i]=='>') { r[i] = r[i+1]+1; }
    else if(s[i]=='<') { r[i] = 0; }
  }

  /*
  for(lint i=0;i<n;i++) { cout << l[i]; }
  cout << endl;
  for(lint i=0;i<n;i++) { cout << r[i]; }
  cout << endl;
  */

  lint sum=0;
  for(lint i=0;i<n;i++) {
    if(l[i] > r[i]) { sum += l[i]; }
    else { sum += r[i]; }
  }

  cout << sum << endl;
  return 0;
}
