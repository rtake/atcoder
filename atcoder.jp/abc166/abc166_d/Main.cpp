# include <cstdio>
# include <cmath>
# include <vector>

using namespace std;

int calc_ab_polynomial( int a, int b ) { return ( pow( a, 5 ) - pow( b, 5 ) ); }

int main(void) {
  int x, i, j, a = 0, b = 0, chk = 0; scanf( "%d", &x );
  for(i = 119;i > -119;i--) {
    chk = 0;
    for(j = 118;j > -120;j--) {
      if( calc_ab_polynomial( i, j ) == x ) {
        chk = 1; a = i; b = j;
        printf( "%d %d\n", i, j );
        break;
      }
    }
    if( chk == 1 ) { break; }
  }
  return 0; 
}  