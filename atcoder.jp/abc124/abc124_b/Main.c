#include <stdio.h>

int main(void)
{
  int ans = 0,N,i = 0,highest = 0;
  scanf("%d",&N);
  int H[N];
  for(i = 0;i < N;i++) {
    scanf("%d",&H[i]);
    if(H[i] >= highest) {
      highest = H[i];
      ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}