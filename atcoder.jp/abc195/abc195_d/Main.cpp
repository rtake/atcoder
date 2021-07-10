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
  int n,m,q; cin >> n >> m >> q;
  vector<int> w(n), v(n); for(int i=0;i<n;i++) cin >> w[i] >> v[i];
  vector<int> x(m); for(int i=0;i<m;i++) cin >> x[i];

  vector< pair<int,int> > p;
  for(int i=0;i<n;i++) p.push_back(pair<int,int>(v[i],w[i]));
  sort(p.begin(), p.end(), greater< pair<int,int> >());

  for(int i=0;i<q;i++) {
    int l,r; cin >> l >> r; l--; r--;
    int ans=0;
    vector<int> xsub;

    for(int j=0;j<m;j++) {
      if(j<l || r<j) xsub.push_back(x[j]);
    }

    sort(xsub.begin(), xsub.end());

    for(auto itr_p:p) {

      int pos=0;
      for(auto itr_x:xsub) {
        if(itr_p.second <= itr_x) {
          ans += itr_p.first;
          xsub.erase(xsub.begin()+pos);
          break;
        }
        pos++;
      }

    }

    cout << ans << endl;
  }

  return 0;
}