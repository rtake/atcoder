# include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i,n) for (lint i=0; i<(lint)(n);i++)

vector< pair<ll,bool> > bellman_ford
(vector< vector< pair<ll,ll> > > G, ll start) {
  ll inf=1e18;

  ll n=G.size();

  vector< pair<ll,bool> > dd(n,{inf,false});

  dd[start].first=0;

  for(ll i=0;i<n-1;i++) {
    for(ll j=0;j<n;j++) {
      for(auto edge:G[j]) {
        dd[edge.second].first=	\
         min(dd[edge.second].first,dd[j].first+edge.first); // update
      } // for all edges
    } // for all nodes
  } 

  for(ll j=0;j<n;j++) {
    for(auto edge:G[j]) {
      if(dd[edge.second].first > dd[j].first+edge.first) {
        dd[edge.second].second=true;
      } else {
        if(dd[j].second) dd[edge.second].second=true;
      }
    } // for all edges
  } // for all nodes
  
  return dd;
}


int main() {

  return 0;
}
