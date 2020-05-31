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
  lint n,k; cin >> n >> k;

  map<lint,lint> mp;
  set<lint> st;
  for(lint i=0;i<n;i++) {
    lint a,b; cin >> a >> b;
    mp[a] += b;
    st.insert(a);
  }

  lint cnt=0, ans;
  for(set<lint>::iterator itr=st.begin();itr!=st.end();itr++) {
    cnt += mp[*itr];
    if(cnt >= k) {
      ans = *itr;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
