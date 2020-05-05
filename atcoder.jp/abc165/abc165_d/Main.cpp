# include <iostream>
using namespace std;

int main() {
  long long int a,b,n, x_max, v_max; cin >> a >> b >> n;

  if( n/b < 1 ) { x_max = n; }
  else{ x_max = ( (n/b+1) - 1 ) * b + (b-1); }
  v_max = (a*x_max/b) - a*(x_max/b);
  cout << v_max << endl;

  return 0;
}