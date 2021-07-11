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
  return n*(P(n-1,k-1));
}


std::vector<std::vector<long long>> comb(int n, int r) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}


int score(vector<int> v) {
  int val=0;
  for(int i=1;i<=9;i++) val += i*pow(10,v[i]);
  return val;
}


int main() {
  lint k; cin >> k;
  string s,t; cin >> s >> t;

  vector<int> vs(10,0), vt(10,0);
  for(int i=0;i<4;i++) {
    vs[s[i]-'0']++;
    vt[t[i]-'0']++;
  }

  vector<int> v(10,0);
  for(int i=1;i<=9;i++) v[i] = vs[i] + vt[i];


  lint ans=0;
  for(int i=1;i<=9;i++) {

    for(int j=1;j<=9;j++) {
      vector<int> vsub=v, vssub=vs, vtsub=vt;

      // vsub[i]++; vsub[j]++;
      if(vsub[i]+1>k) continue;
      if(vsub[j]+1>k) continue;

      vssub[i]++; vtsub[j]++;
      if(score(vssub) > score(vtsub)) {
        if(i==j) ans+=(k-vsub[i])*(k-vsub[i]-1);
        else ans+=(k-vsub[i])*(k-vsub[j]);
        // cout << ans << " " << k-vsub[i] << " " << k-vsub[j] << endl;
      }
    }

  }

  // cout << ans << endl;
  printf("%.12lf\n", (double)ans/(9*k-8)/(9*k-9));
  return 0;
}
