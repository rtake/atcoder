# include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i,n) for (ll i=0; i<(ll)(n);i++)

// https://drken1215.hatenablog.com/entry/2019/02/15/141000#fn:1
vector< vector< pair<ll,ll> > > G;
set<pair<int,int> > use;

vector<ll> dijkstra(vector< vector< pair<ll,ll> > > G, ll start) {
  vector<ll> dist((ll)G.size(),1e18);
  vector< vector<ll> > prev((ll)G.size());
  priority_queue< pair<ll,ll>,
                  vector< pair<ll,ll> >,
                  greater< pair<ll,ll> > > Q;

  dist[start]=0;
  Q.emplace(0,start);

  while(!Q.empty()) {
    auto cur=Q.top(); Q.pop();
    ll cur_d=cur.first;
    ll cur_v=cur.second;

    if(dist[cur_v] < cur_d) continue; // 枝狩り

    for(auto next:G[cur_v]) {
      ll next_d=next.first;
      ll next_v=next.second;

      ll alt=cur_d+next_d;

      if(alt < dist[next_v]) {
        dist[next_v]=alt;
        Q.emplace(alt,next_v);

        prev[next_v].clear();
        prev[next_v].push_back(cur_v);
      } else if(alt == dist[next_v]) {
        prev[next_v].push_back(cur_v);
      }
    }
  }

  for(ll v=0;v<(ll)G.size();v++) {
    for(auto u:prev[v]) {
      use.insert(make_pair(min(u,v),max(u,v)));
    }
  }

  return dist;
}


int main() {

  return 0;
}
