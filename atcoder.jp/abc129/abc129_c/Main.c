#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  int n,m,i;
  scanf("%d %d",&n,&m);
  int a[m],b[n + 1];
  for(i = 0;i < n + 1;i++) {
    b[i] = 1;  
  }
  b[0] = 1;
  b[1] = 1;
  
  for(i = 0;i < m;i++) {
    scanf("%d\n",&a[i]);
    b[a[i]] = 0;
  }
  

  for(i = 2;i < n + 1;i++) {
    if(b[i] == 0) continue;
    b[i] = (b[i - 2] + b[i - 1]) % 1000000007;
    //printf("%d\n",b[i]);
  }
  
  printf("%d\n",b[n]);
  
  return 0;
}