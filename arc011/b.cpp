# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%1000000007;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%1000000007;
}


int main() {
  int n; cin>>n;
  vector<string> w(n); for(int i=0;i<n;i++) cin>>w[i];

  map<char,char> mp;
  for(int i=0;i<26;i++) {
    char test='a'+i;
    if(test == 'b' || test == 'c') mp[test] = '1';
    else if(test == 'd' || test == 'w') mp[test] = '2';
    else if(test == 't' || test == 'j') mp[test] = '3';
    else if(test == 'f' || test == 'q') mp[test] = '4';
    else if(test == 'l' || test == 'v') mp[test] = '5';
    else if(test == 's' || test == 'x') mp[test] = '6';
    else if(test == 'm' || test == 'p') mp[test] = '7';
    else if(test == 'z' || test == 'r') mp[test] = '0';
    else if(test == 'g' || test == 'n') mp[test] = '9';
    else if(test == 'h' || test == 'k') mp[test] = '8';
  }


  bool is_first_element=true;
  for(int i=0;i<n;i++) {

    deque<char> dq;
    for(auto x:w[i]) {
      if(mp[tolower(x)]) dq.push_back(mp[tolower(x)]);
    }
 
    if(!dq.empty()) {
      if(!is_first_element) dq.push_front(' ');
      is_first_element = false;
    }

    for(auto y:dq) cout<<y;
  }

  cout << endl;
  return 0;
}
