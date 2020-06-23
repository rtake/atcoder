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

string s;
int solve(int index) {
  if(index==-1) { return 0; }
  
  if(index-5+1 >= 0 && s.substr(index-5+1,5) == "dream") { return solve(index-5); }
  else if(index-7+1 >= 0 && s.substr(index-7+1,7) == "dreamer") { return solve(index-7); }
  else if(index-5+1 >= 0 && s.substr(index-5+1,5) == "erase") { return solve(index-5); }
  else if(index-6+1 >= 0 && s.substr(index-6+1,6) == "eraser") { return solve(index-6); }
  
  return -1;
}

int main() {
  cin >> s;
  int size=(int)s.size();

  int ans=solve(size-1);

  if(ans==0) { cout << "YES" << endl; }
  else { cout << "NO" << endl; }
  return 0;
}
