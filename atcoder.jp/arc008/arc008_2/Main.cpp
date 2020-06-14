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
  int n,m;
  cin >> n >> m;
  string name, kit; // char name[n], kit[m];  
  cin >> name >> kit;

  map<char,int> mp_name, mp_kit;
  for(int i=0;i<n;i++) { mp_name[name[i]]++; }
  for(int i=0;i<m;i++) { mp_kit[kit[i]]++; }
  
  int ans=0;
  /*
  for(map<char,int>::iterator itr=mp_name.begin();itr!=mp_name.end();itr++) {
    if(mp_kit[itr->first] == 0) { 
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans,(mp_name[itr->first]+mp_kit[itr->first]-1)/mp_kit[itr->first]);
  }
  */

   for(auto itr : mp_name) {
    if(mp_kit[itr.first] == 0) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans,(itr.second+mp_kit[itr.first]-1)/mp_kit[itr.first]);
   }

  cout << ans << endl;
  return 0;
}
 