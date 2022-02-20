# include <bits/stdc++.h>

typedef long long ll;
typedef long long lint;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

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
  ll n,k;
  cin>>n>>k;
  vector<ll> p(n),c(n);
  rep(i,n) cin>>p[i];
  rep(i,n) cin>>c[i];

  rep(i,n) p[i]--;

  vector<ll> ans;

  rep(i,n) {
    vector<ll> vmax(1,-1e18); // max score starting from i
    vector<ll> check(n,-1);
    ll cnt=0;
    ll pos=i;
    ll score=0;

    while(true) {
      if(cnt > k) {
        ans.push_back(vmax[cnt-1]);
        break;
      }

      if(check[pos] != -1) {
        // arrived 
        ll t=cnt-check[pos]; // 

        if(score < 0) {
          ans.push_back(vmax[cnt]);
          // ans.push_back(vmax[cnt-1]);
        } else {
          if(k%t == 0) ans.push_back(score*(k/t));
          else ans.push_back(score*(k/t)+vmax[k%t]);
        }

        break;
      }

      check[pos]=cnt;
      pos=p[pos]; // update pos
      score+=c[pos]; // update score

      vmax.push_back(max(vmax[cnt],score));

      cnt++;
    }

  }

  // for(auto v:ans) cout<<v<<endl;
  cout<<*max_element(ans.begin(), ans.end())<<endl;

  return 0;
}
