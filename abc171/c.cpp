# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }

lint C(lint n, lint k) {
  if(n == k) { return 1; }
  else if(n < k) { return 0; }
  else if(k == 0) { return 1; }
  else if(k == 1) { return n; }
  else return C(n-1,k-1) + C(n-1,k);
}

lint P(lint n, lint k) {
  if(k == 1) { return n; }
  return (n*(P(n-1,k-1)%1000000007)%1000000007);
}


int main() {
  lint n; cin >> n;

  if(n<=26) {
    cout << (char)('a'+(26-1)) << endl;
    return 0;
  }

  string s;
  lint cnt=0, cur=26;
  while(true) {
    if(n<=cur+cur/26) { break; }
    cnt++;
    cur*=26;
  }

  cur /= 26;
  n -= (cur+cur/26+1);
  for(int i=cnt;i>=0;i--) {
    s += 'a'+n/cur;
    n %= cur;
    cur /= 26;
  } 
  
  cout << s << endl;
  return 0;
}
