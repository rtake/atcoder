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
  lint N,M,Q; cin >> N >> M >> Q;
 
  vector<lint> score(N,0);
  vector< vector<lint> > problems(M);

  for(lint i=0;i<Q;i++) {
    int s,n,m; cin >> s;
    if(s == 1) {
      cin >> n;
      cout << score[n-1] << endl;
    } else {
      cin >> n >> m;
      for(int i=0;i<(int)problems[m-1].size();i++) { score[problems[m-1][i]] = max(--score[problems[m-1][i]],0LL); }
      problems[m-1].push_back(n-1);
      score[n-1] += N-(int)problems[m-1].size();
    }
  }

  return 0;
}
