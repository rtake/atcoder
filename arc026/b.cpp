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
  lint n; cin>>n;

  lint nsub=n;
  set<lint> st;
  for(lint i=2;i*i<=n;i++) {
    if(n%i == 0) {
      st.insert(i);
      st.insert(n/i);
    }
  }

  lint sum=1;
  for(auto x:st) sum+=x;

  if(nsub == 1) cout<<"Deficient\n";
  else if(sum == nsub) cout<<"Perfect\n";
  else if(sum < nsub) cout<<"Deficient\n";
  else if(sum > nsub) cout<<"Abundant\n";
   
  return 0;
}
