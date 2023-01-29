#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
  int n,m,e;
  cin >> n >> m >> e;
  vector<int> u(e),v(e);
  for(int i=0;i<e;i++){
    cin >> u[i] >> v[i];
    u[i]--;v[i]--;
  }

  vector<int> fl(e,1);
  int q;
  cin >> q;
  vector<int> query(q);
  for(auto &nx : query){
    cin >> nx;
    nx--;
    fl[nx]=0;
  }

  dsu uf(n+m);
  vector<int> w(n+m,0);
  for(int i=n;i<n+m;i++){w[i]=1;}
  int cur=0;
  for(int i=0;i<e;i++){
    if(fl[i]==0){continue;}
    // if(uf.same(u[i],v[i])){continue;}
    int fu=w[uf.leader(u[i])];
    int fv=w[uf.leader(v[i])];
    if(fu==0 && fv==1){cur+=uf.size(u[i]);}
    if(fu==1 && fv==0){cur+=uf.size(v[i]);}
    uf.merge(u[i],v[i]);
    w[uf.leader(u[i])]=max(fu,fv);
  }
  
  vector<int> res;
  for(int j=q-1;j>=0;j--){
    int i=query[j];
    res.push_back(cur);
    // if(uf.same(u[i],v[i])){continue;}
    int fu=w[uf.leader(u[i])];
    int fv=w[uf.leader(v[i])];
    if(fu==0 && fv==1){cur+=uf.size(u[i]);}
    if(fu==1 && fv==0){cur+=uf.size(v[i]);}
    uf.merge(u[i],v[i]);
    w[uf.leader(u[i])]=max(fu,fv);
  }
  
  reverse(res.begin(),res.end());
  for(auto &nx : res){cout << nx << "\n";}
  return 0;
}

