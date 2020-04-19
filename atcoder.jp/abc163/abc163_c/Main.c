#include <math.h>
#include <stdio.h>

int main(void)
{
  int i, n; scanf( "%d", &n );
  int a[n], b[n], sum = 0;
  a[0] = -1;
  for(i = 1;i < n;i++) { scanf( "%d", &a[i] ); }
  for(i = 0;i < n;i++) { b[i] = 0; } // init
  
  for(i = 1;i < n;i++) { b[ a[i] -1 ]++ ; }
  for(i = 0;i < n;i++) { printf( "%d\n", b[i] ); }
  
  return 0;
}