#include <iostream>
#include <cstdlib>
#define INF 100000000
using namespace std;
int N,A,B,C,l[10];
int dfs(int cur,int a,int b,int c);
int main(void)
{
  cin >> N >> A >> B >> C;
  for(int i=0;i<N;i++) {
    cin >> l[i];
  }
  cout << dfs(0,0,0,0) << "\n";
  return 0;
}
int dfs(int cur,int a,int b,int c)
{
  if(cur==N) {
    if(a>0&&b>0&&c>0) {
      return abs(a-A)+abs(b-B)+abs(c-C)-30;
    } else {
      return INF;
    }
  }
  int r0=dfs(cur+1,a,b,c);
  int r1=dfs(cur+1,a+l[cur],b,c)+10;
  int r2=dfs(cur+1,a,b+l[cur],c)+10;
  int r3=dfs(cur+1,a,b,c+l[cur])+10;
  return min(r0,min(r1,min(r2,r3)));
}
