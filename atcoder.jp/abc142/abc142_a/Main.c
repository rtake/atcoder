#include <stdio.h>

int main(void)
{
  int n;
  double ans;
  scanf("%d",&n);
  
  if(n == 1) ans = 1.000000;
  else if(n %2 == 0) ans = 0.5000000;
  else if(n %2 == 1) ans = (n / 2 + 1) / (double)n;

  printf("%17.12lf\n",ans);
  
  return 0;
}
