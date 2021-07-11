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
  int n,m; cin >> n >> m;
  vector<int> a(m),b(m),c(m);
  for(int i=0;i<m;i++) cin >> a[i] >> b[i] >> c[i];

  vector< vector< vector<int> > > ans(n, vector< vector<int> >(n, vector<int>(n,0)));
  // map<int, pair<int,int>> mp;
  map<pair<int,int>, int> mp0;
  for(int i=0;i<m;i++) mp0[pair<int,int>(a[i]-1,b[i]-1)] = c[i];

  for(int k=0;k<n;k++) {
    
    for(auto x:mp0) {
      int prev=cur.x.first.first, cur=x.first.second, sum=x.second;
      vector< pair<int,int> > vp;

      do {
        


      } while(!vp.empty());


    }

  }


  /*
  map<pair<int,int>, int> mp1;
  for(int s=0;s<n;s++) {
    for(int t=0;t<n;t++) {

      for(int k=0;k<n;k++) {
        if(s==t) continue;

        for(auto x:mp1) {
          if(x.first.first )

        }


        if(ans[s][t][k] <= 0) ans[s][t][k] = mp1[pair<int,int>(s,t)];
        else ans[s][t][k] = min(ans[s][t][k], mp1[pair<int,int>(s,t)]);
        mp1[pair<int,int>(s,t)] = ans[s][t][k];
      }

    }
  }
  */

  return 0;
}
