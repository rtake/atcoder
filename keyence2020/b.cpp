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
  vector< pair<lint,lint> > vp(n);
  for(lint i=0;i<n;i++) { cin >> vp[i].first >> vp[i].second; }

  sort(vp.begin(),vp.end());
  vector<lint> check(n+1,-9999999); // min(max)
  lint cur=0; // current number of arms
  for(lint i=0;i<n;i++) {
    if(check[cur] <= vp[i].first - vp[i].second) {
      check[++cur] = vp[i].first + vp[i].second; // add the arm
    } 
  } // for each arm

  cout << cur << endl;
  return 0;
}
