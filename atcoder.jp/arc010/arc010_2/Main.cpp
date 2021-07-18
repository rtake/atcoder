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
  int n; cin>>n;
  // vector<int> m,d;
  vector< pair<int,int> > v(n);
  for(int i=0;i<n;i++) {
    string s,buf; cin>>s;
    stringstream ss(s);

    getline(ss,buf,'/'); v[i].first = stoi(buf);
    getline(ss,buf,'/'); v[i].second = stoi(buf);
  }

  sort(v.begin(), v.end());

  vector<int> days(13), days_sum(13,0);
  for(int i=1;i<=12;i++) {
    if(i==2) days[i]=29;
    else if(i==4 || i==6 || i==9 || i==11) days[i]=30;
    else days[i]=31;
  }

  for(int i=2;i<=12;i++) days_sum[i] = days_sum[i-1] + days[i-1];

  vector<bool> is_holiday(366+1,false);
  for(int i=1;i<=366;i++) {
    if(i%7 == 1 || i%7 == 0) is_holiday[i] = true;
  }

  for(int i=0;i<n;i++) {
    for(int j=0;;j++) {
      if(!is_holiday[days_sum[v[i].first]+v[i].second+j]) {
        is_holiday[days_sum[v[i].first]+v[i].second+j] = true;
        break;
      }
    }
  }

  int ans=2, cnt=0;
  for(int i=1;i<=365;i++) {
    if(is_holiday[i] && is_holiday[i+1]) cnt++;
    else {
      ans = max(ans,cnt+1);
      cnt=0;
    }
  }

  cout<<max(ans,cnt+1)<<endl;
  return 0;
}