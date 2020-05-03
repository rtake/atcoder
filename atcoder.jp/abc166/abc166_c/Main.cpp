# include <cstdio>
# include <vector>

using namespace std;

int main(void) {
  int n, m, i, j, ans = 0;
  scanf( "%d %d", &n, &m );
  vector<int> h( n, 0 ), a( m, 0 ), b( m, 0 ), c( n, 0 );
  for(i = 0;i < n;i++) { scanf( "%d", &h[i] ); }
  for(i = 0;i < m;i++) { scanf( "%d %d\n", &a[i], &b[i] ); }
  
  for(i = 0;i < m;i++) {
    if( h[a[i] - 1] > h[b[i] - 1] ) {
      c[b[i] - 1] = -1;
      if( c[a[i] - 1] >= 0 ) { c[a[i] - 1] = a[i]; }
    } else if( h[a[i] - 1] < h[b[i] - 1] ) {
      c[a[i] - 1] = -1;
      if( c[b[i] - 1] >= 0 ) { c[b[i] - 1] = b[i]; }
    } else {
      c[a[i] - 1] = -1;
      c[b[i] - 1] = -1;
    }
  }

  for(i = 0;i < n;i++) { if( c[i] >= 0 ) ans++; }
  printf( "%d\n", ans );  
  
  return 0; 
}  