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
  int n,c; cin>>n>>c;
  vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];

  vector< pair<int,int> > ev(10), od(10);
  for(int i=0;i<10;i++) {
    ev[i].first = 0; ev[i].second = i;
    od[i].first = 0; od[i].second = i;
  }
  
  for(int i=0;i<n;i++) {
    if(i%2 == 0) od[a[i]-1].first++;
    else ev[a[i]-1].first++;
  }

  sort(ev.begin(), ev.end(), greater< pair<int,int> >());
  sort(od.begin(), od.end(), greater< pair<int,int> >());

  int ans=c;
  if(ev[0].second == od[0].second) {
    if(ev[0].first > od[0].first) ans *= n-ev[0].first-max(ev[1].first, od[1].first);
    else ans *= n-od[0].first-max(od[1].first, ev[1].first);
  } else ans *= n-ev[0].first-od[0].first;

  printf("%d\n", ans);
  return 0;
}
