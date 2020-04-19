#include <math.h>
#include <stdio.h>

int main(void)
{
  int i, n,m; scanf( "%d %d", &n, &m );
  int a[m], sum = 0;
  for(i = 0;i < m;i++) { scanf( "%d", &a[i] ); }
  for(i = 0;i < m;i++) { sum += a[i]; }
  if( n - sum < 0 ) { printf( "-1\n" ); }
  else { printf( "%d\n", n - sum );}
  return 0;
}