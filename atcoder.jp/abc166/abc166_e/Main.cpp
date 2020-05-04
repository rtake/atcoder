# include <cstdio>
# include <algorithm>
# include <vector>

using namespace std;

int main(void) {
  long long int cnt = 0, n, i; scanf( "%lld", &n );
  vector<long long int> a( n ), a_plus( n ), a_minus( n ), ans( n, 0 );
  for(i = 0;i < n;i++) { scanf( "%lld", &a[i]) ; }
  for(i = 0;i < n;i++) { a_plus[i] = i + a[i]; a_minus[i] = i - a[i]; }
  for(i = 0;i < n;i++) { if( a_plus[i] < n ) { ans[ a_plus[i] ]++; } }
  for(i = 0;i < n;i++) { if( a_minus[i] < n && a_minus[i] > 0 ) { cnt += ans[ a_minus[i] ]; } }
  printf( "%lld\n", cnt );
  
  return 0;
}