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

// vector<int> mat(200000,-1);

int popcount(int x, int n) {
  int cnt=0, cur=1;

  for(int i=0;i<n-1;i++) { cur *= 2; }
  for(int i=0;i<n;i++) {
    if(x%cur == 0) {
      cnt++;
      x /= cur;
    }
  }

  return cnt;
}

int f(string s,int n) {
  int ret;

  return ret;
}

int main() {
  lint n; cin >> n;
  string x; cin >> x;

  for(int i=0;i<n;i++) {
    string x0 = x;
    if(x0[i]=='0') { x0[i]=1; }
    else { x0[i]=0; }
    cout << f(x0,n) << endl;
  }
  
  return 0;
}
