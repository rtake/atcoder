# include <cstdio>

int main() {
  long long int x,i,sum = 100; scanf("%lld",&x);
  for(i = 0;;i++) {
    sum *= 1.01;
    if( sum >= x ) { break; }
  }
  printf("%lld\n",i+1);
  return 0;
}