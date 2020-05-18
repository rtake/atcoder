# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return abs(x-y)/gcd(x,y); }


int main() {
  lint n,m; cin >> n >> m; 
  vector<lint> a(m,0),b(m,0); for(lint i=0;i<m;i++) { cin >> a[i] >> b[i]; }

  vector< vector<lint> > mat(n);
  vector<int> check(n,-1);

  
  for(lint i=0;i<m;i++) {
    mat[a[i]-1].push_back(b[i]-1);
    mat[b[i]-1].push_back(a[i]-1);
  }

  queue<lint> q;
  q.push(0);

  while(!q.empty()) {
    lint elem = q.front();
    q.pop();
    lint size=(int)mat[elem].size();

    for(lint i=0;i<size;i++) {
      if( check[mat[elem][i]] == -1 ) {
        check[mat[elem][i]] = elem;
        q.push(mat[elem][i]);
      }
    }
  }

  for(lint i=1;i<n;i++) {
    if(check[i] == -1) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  for(lint i=1;i<n;i++) { cout << check[i]+1 << endl; }
  return 0;
}
