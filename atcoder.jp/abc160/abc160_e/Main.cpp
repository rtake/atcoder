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
  lint x,y,a,b,c; cin>>x>>y>>a>>b>>c;
  vector<lint> p(a); rep(i,a) cin>>p[i];
  vector<lint> q(b); rep(i,b) cin>>q[i];
  vector<lint> r(c); rep(i,c) cin>>r[i];

  sort(p.begin(), p.end(), greater<lint>());
  sort(q.begin(), q.end(), greater<lint>());
  sort(r.begin(), r.end(), greater<lint>());

  priority_queue<lint, deque<lint>, greater<lint> > red,green;
  // priority_queue<lint, deque<lint>, greater<lint> > rque;
  priority_queue<lint, deque<lint>, less<lint> > rque;
  rep(i,x) red.push(p[i]);
  rep(i,y) green.push(q[i]);
  rep(i,c) rque.push(r[i]);

  /*
  cout<<endl<<"red"<<endl;
  while(!red.empty()) {
    cout<<red.top();
    red.pop();
  }
  cout<<endl;

  cout<<endl<<"green"<<endl;
  while(!green.empty()) {
    cout<<green.top();
    green.pop();
  }
  cout<<endl;
  */

  lint buf;
  while(rque.top() > red.top()) {
    buf=red.top();
    red.pop();
    red.push(rque.top());

    rque.pop();
    rque.push(buf);
  }

  while(rque.top() > green.top()) {
    buf=green.top();
    green.pop();
    green.push(rque.top());

    rque.pop();
    rque.push(buf);
  }

  lint sum=0;
  while(!red.empty()) {
    sum+=red.top();
    red.pop();
  }

  while(!green.empty()) {
    sum+=green.top();
    green.pop();
  }


  printf("%lld\n", sum);
  return 0;
}