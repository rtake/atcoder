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
  int n,ng1,ng2,ng3; cin >> n >> ng1 >> ng2 >> ng3;

  if(n==ng1 || n==ng2 || n==ng3) {
    cout << "NO\n";
    return 0;
  }

  for(int i=0;i<100;i++) { //cout << n << endl;
    if(n-3!=ng1 && n-3!=ng2 && n-3!=ng3 && n-3>=0) { n-=3; }
    else if(n-2!=ng1 && n-2!=ng2 && n-2!=ng3 && n-2>=0) { n-=2; }
    else if(n-1!=ng1 && n-1!=ng2 && n-1!=ng3 && n-1>=0) { n-=1; }

    if(n==0) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}
