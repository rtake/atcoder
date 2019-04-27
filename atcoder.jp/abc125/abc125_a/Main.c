#include <stdio.h>

int main(void)
{
  int A,B,T;
  scanf("%d %d %d",&A,&B,&T);

  int ans = (T / A) * B;

  printf("%d\n",ans);



  return 0;
}
