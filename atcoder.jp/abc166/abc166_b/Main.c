# include <stdio.h>
# include <string.h>

int main(void) {
  int n, k, i, j, ichk, cnt = 0;
  scanf( "%d %d", &n, &k );
  int d[k], a[n]; 
  for(i = 0;i < n;i++) { a[i] = 0; }
  for(i = 0;i < k;i++) {
    scanf( "%d", &d[i] );  
    for(j = 0;j < d[i];j++) {
      scanf( "%d", &ichk );
      a[ichk - 1] = 1;
    }    
  }  

  for(i = 0;i < n;i++) { if( a[i] == 0 ) { cnt++; } }
  printf( "%d\n", cnt );
  
  return 0; 
}  