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

  lint n0=n, ans=0;
  map<lint,lint> mp;
  set<lint> st;

  for(lint i=2;i*i<=n;i++) {
    while(n0%i == 0) {
      n0 /= i;
      mp[i]++;
      st.insert(i);
    }
  }

  if(n0 > 1) {
    mp[n0]++;
    st.insert(n0);
  }

  for(set<lint>::iterator itr=st.begin();itr!=st.end();itr++) {
    lint num=0;
    for(num=0;;num++) {
      if(num*(num+1)/2 > mp[*itr]) { break; }
    }
    ans += num-1;
  }

  cout << ans << endl;  
  return 0;
}
