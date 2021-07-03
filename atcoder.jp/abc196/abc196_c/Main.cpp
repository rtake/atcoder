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
  string n; cin >> n;
  int length=(int)n.size();

  int ans=1;
  if(length%2 != 0) {
    for(int i=0;i<length/2;i++) ans*=10;
    ans--;
  } else {
    int l=stoi(n.substr(0,length/2)), r=stoi(n.substr(length/2, length/2));
    if(l<=r) ans=l;
    else ans=l-1;
  }

  printf("%d\n", ans);
  return 0;
}
