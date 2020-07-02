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
  lint n,q; cin >> n >> q;
  vector<int> r(n+1,0); // root
  for(int i=0;i<n-1;i++) {
    int a,b; cin >> a >> b;
    r[b] = a;
  }

  vector<int> s(n+1,0); // sum
  for(int i=0;i<q;i++) {
    int p,x; cin >> p >> x;
    s[p] += x;
  }

  for(int i=0;i<n;i++) {
    int sum=0, cur=i+1;
    while(true) {
      sum += s[cur];
      if(cur == 1) { break; }
      cur = r[cur]; // root
    }
    printf("%d ",sum);
  }

  cout << endl;
  return 0;
}
