# include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

pair< vector<ll>, vector<bool> > bellman_ford
(ll n, vector< pair< pair<ll,ll>, ll> > V, ll start) {
  ll inf=1e18;

  vector<ll> d(n,inf);
  vector<bool> negative(n,false);

  d[start]=0;

  for(ll i=0;i<n-1;i++) {
    for(auto edge:V) {
      auto p=edge.first;
      ll from=p.first;
      ll to=p.second;
      ll cost=edge.second;

      if(d[from] != inf && d[to] > d[from]+cost) d[to]=d[from]+cost;
    } // for all edge
  }


  for(ll i=0;i<n-1;i++) {
    for(auto edge:V) {
      auto p=edge.first;
      ll from=p.first;
      ll to=p.second;
      ll cost=edge.second;

      if(d[from] != inf && d[to] > d[from]+cost) {
        d[to]=d[from]+cost;
        negative[to]=true;
      }

      if(negative[from]) negative[to]=true;
    } // for all edges
  }

  return make_pair(d,negative);
}


int main() {

  return 0;
}
