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
  lint N; scanf("%lld\n", &N); // cout << N << endl;
  vector<lint> A(N); for(lint i=0;i<N;i++) { scanf("%lld ", &A[i]); }
  sort(A.begin(), A.end());
  
  lint sum=1;
  set<vector<lint>> st_all, st_cur;
  st_all.insert(A);
  st_cur = st_all;

  for(lint depth=0;depth<N;depth++) {
    set<vector<lint>> st0;

    for(set<vector<lint>>::iterator itr=st_cur.begin();itr!=st_cur.end();itr++) {
      vector<lint> a=*itr;

      for(lint x=*max_element(a.begin(), a.end());x>0;x--) {
        vector<lint> b=a;

        for(lint i=0;i<N;i++) {
          if(x <= a[i]) {
            a[i] = max(a[i]-1,(lint)0);
          }
        }

        st0.insert(a);
        st_all.insert(a);
      }

      /*
      for(lint i=N-1;i>=0;i--) {
        a[i] = min(max(a[i]-1,(lint)0), x);
        // sort(a.begin(), a.end());

        st0.insert(a);
        st_all.insert(a);

        // for(lint j=0;j<N;j++) { printf("%lld ", a[j]); }
        // cout << endl;
      }
      */

    }

    // cout << (lint)st_all.size() << endl;
    cout << (lint)st0.size() << endl;
    st_cur=st0;
  }

  /*
  while(depth<N) {

    for(lint i=0;i<N;i++) {

    }

    depth -= 2;

    if(depth <= 1) { break; }
  }
  */

  printf("%lld\n", (lint)st_all.size());

  return 0;
}
