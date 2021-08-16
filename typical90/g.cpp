# include <bits/stdc++.h>
//# include <atcoder/all>

typedef long long lint;

using namespace std;
//using namespace atcoder;

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

// Segment tree
lint op(lint a, lint b) { return a^b; }
lint e() { return 0LL; }

int main() {
  lint n; cin>>n;
  vector<lint> a(n); rep(i,n) cin>>a[i];
  lint q; cin>>q;
  vector<lint> b(q); rep(i,q) cin>>b[i];

  vector< pair<lint,lint> > vpa,vpb, ans;
  rep(i,n) vpa.emplace_back(a[i],i);
  rep(i,q) vpb.emplace_back(b[i],i);

  sort(vpa.begin(), vpa.end());
  sort(vpb.begin(), vpb.end());

  /*
  rep(i,n) cout<<vpa[i].first<<endl;
  cout<<endl;
  rep(i,q) cout<<vpb[i].first<<endl;
  cout<<endl;
  */

  auto a_itr=vpa.begin();
  auto b_itr=vpb.begin();
  while(b_itr != vpb.end()) {

    lint value=abs((vpa.end()-1)->first - b_itr->first);
    while(a_itr != vpa.end()) {
      
      // cout<<a_itr->first<<" "<<b_itr->first<<endl;

      if(a_itr->first >= b_itr->first) {
        if(a_itr != vpa.begin()) {
          auto prev=a_itr-1;
          value=abs(a_itr->first - b_itr->first);
          value=min(value,abs(prev->first - b_itr->first));
          // cout<<value<<endl<<endl;
          a_itr--;
        } else {
          value=abs(a_itr->first - b_itr->first);
          // cout<<a_itr->first<<" "<<b_itr->first<<endl;
        }

        break;
      }

      a_itr++;
    }

    // value=min(value,abs(b_itr->first - (a_itr-1)->first));
    ans.emplace_back(value, b_itr->second);

    b_itr++;
  }

  rep(i,q) swap(ans[i].first, ans[i].second);
  sort(ans.begin(), ans.end());

  rep(i,q) cout<<ans[i].second<<endl;

  return 0;
}
