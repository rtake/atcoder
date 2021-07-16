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
  string s; cin>>s;
  int l=s.length();

  int ans=0, cur=0;
  char lastword=' ';
  vector<bool> is_checked('z'-'a'+1, false);
  for(int i=1;i<l;i++) {
    if(s[i] == s[i-1]) {
      if(!is_checked[s[i]-'a']) {
        ans += (cur-1);
        ans += (l-i);

        cur=0;
        is_checked[s[i]-'a'] = true;
        lastword = s[i];
      }
    } else {
      if(lastword != ' ' && s[i] == lastword) cur++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
