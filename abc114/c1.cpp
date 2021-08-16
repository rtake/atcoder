# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

lint gcd(lint x, lint y) { return (x==0)? y : gcd(y%x,x); }
lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }
lint P(lint n, lint k) { return (k==1) ? n : n*(P(n-1,k-1)); }

lint mod=1000000007;
lint comb[2000][2000];
lint nCr(lint n, lint r) {
  if(n==r) return comb[n][r] = 1;
  if(r==0) return comb[n][r] = 1;
  if(r==1) return comb[n][r] = n;
  if(comb[n][r]) return comb[n][r]%mod;
  return comb[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

lint inv(lint x) {
  lint res=1, k=mod-2;
  while(k>0) {
    if(k&1 == 1) res=(res*x)%mod;
    x=(x*x)%mod;
    k/=2;
  }
  return res;
}

lint nCr_mod(lint n, lint k) {
  lint a=1,b=1;
  for(int i=0;i<k;i++) a=(a*(n-i))%mod;
  for(int i=0;i<k;i++) b=(b*(k-i))%mod;
  return (a*inv(b))%mod;
}

int main() {
  lint n; cin>>n;
  set<lint> st;

  st.insert(357);
  st.insert(375);
  st.insert(537);
  st.insert(573);
  st.insert(735);
  st.insert(753);

  lint cur,cnt=0;
  while(true) {
    cur=*st.begin(); cout<<cur<<endl;
    
    if(cur<=n) cnt++;
    else break;

    stringstream ss;
    ss<<cur;
    lint digit=ss.str().length();

    st.erase(cur);

    st.insert(cur*10+3);
    st.insert(cur*10+5);
    st.insert(cur*10+7);
    st.insert(cur+3*pow(10,digit));
    st.insert(cur+5*pow(10,digit));
    st.insert(cur+7*pow(10,digit));
  }

  printf("%lld\n", cnt);
  return 0;
}
