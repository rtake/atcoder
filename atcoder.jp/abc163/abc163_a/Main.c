#include <math.h>
#include <stdio.h>

int main(void)
{
  int r;
  scanf("%d", &r);
  printf("%lf\n", r * 2 * acos(-1.0) );
  return 0;
}