#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define INF 1000000000000000
using namespace std;
int A,B,Q;
int main(void)
{
  scanf("%d %d %d",&A,&B,&Q);
  vector<long long int> s,t,x;
  int i=0,j=0,k=0;
  long long int input;
  for(i=1;i<=A;i++) {
    cin>>input;
    s.push_back(input);
  }
  s.push_back(INF);
  s.push_back(-INF);
  i=0;
  for(i=1;i<=B;i++) {
    cin>>input;
    t.push_back(input);
  }
  t.push_back(INF);
  t.push_back(-INF);
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  i=0;
  for(i=0;i<Q;i++) {
    cin>>input;
    x.push_back(input);
  }
  for(i=0;i<Q;i++) {
    long long int ans=INF,d[4];
    int sleft=distance(s.begin(),lower_bound(s.begin(),s.end()-1,x[i]))-1;
    int tleft=distance(t.begin(),lower_bound(t.begin(),t.end()-1,x[i]))-1;
    j=k=0;
    for(j=sleft;j<sleft+2;j++) {
      for(k=tleft;k<tleft+2;k++) {
        d[0]=abs(x[i]-s[j])+abs(t[k]-s[j]);
        d[1]=abs(x[i]-t[k])+abs(t[k]-s[j]);
        ans=min(ans,(min(d[0],d[1])));
      }
    }
    printf("%lld\n",ans);
  }
  return 0;
}
