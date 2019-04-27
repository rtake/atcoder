#include <stdio.h>

int main(void)
{
  int N,i = 0,ans = 0;
  scanf("%d",&N);
  int C[N],V[N];
  for(i = 0;i < N;i++) scanf("%d",&V[i]);
  for(i = 0;i < N;i++) scanf("%d",&C[i]);

  for(i = 0;i < N;i++) {

    if(V[i] - C[i] > 0) ans += V[i] - C[i];

  }

  printf("%d\n",ans);

  return 0;
}
