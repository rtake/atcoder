#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
  int N,i = 0;
  scanf("%d",&N);
  double x,ans = 0;
  for(i = 0;i < N;i++) {
    string u;
    cin >> x >> u;
    if(u.find('JPY') != -1) { 
      ans = ans + x;
    } else if(u.find('BTC') != -1) {
      ans = ans + x * 380000;
    }
  }
  printf("%lf\n",ans);
  return 0;
}

