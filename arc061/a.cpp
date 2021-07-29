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

  lint ans=0, l=s.size();
  for(int bit=0;bit<(1<<(l-1));bit++) {

    lint cur=0;
    for(int i=0;i<l-1;i++) {
      if(bit&(1<<i)) {
        ans+=stoll(s.substr(cur,(i-cur)+1));
        cur=i+1;
      }
    }

    ans += stoll(s.substr(cur,(l-1)-cur+1));
  }

  printf("%lld\n", ans);
  return 0;
}
