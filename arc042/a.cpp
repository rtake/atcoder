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
  lint n,m; cin >> n >> m;
  vector<lint> a(m); for(int i=0;i<m;i++) { cin >> a[i]; }

  vector< pair<lint,lint> > vp;
  vector<lint> check(n,0), b;
  for(int i=m-1;i>=0;i--) {
    if(check[a[i]-1] == 1) { continue; } 
    check[a[i]-1] = 1;
    vp.push_back(pair<lint,lint>(i+1,a[i]));
  }
  sort(vp.begin(),vp.end()); 

  for(int i=(int)vp.size()-1;i>=0;i--) { b.push_back(vp[i].second); }
  for(int i=0;i<n;i++) {
    if(check[i]==1) { continue; }
    b.push_back(i+1);
  }

  for(int i=0;i<n;i++) { cout << b[i] << endl; }
  return 0;
}
