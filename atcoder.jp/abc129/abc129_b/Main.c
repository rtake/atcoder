#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  int n,i,sum = 0,test = 0,sub0,sub1;
  scanf("%d\n",&n);
  int w[n];
  for(i = 0;i < n;i++) {
    scanf("%d",&w[i]);
    sum += w[i];
  }
  for(i = 0;i < n;i++) {
    test += w[i];
    if(test >=sum / 2) break;
  }
  sub0 = abs( test - (sum - test) );
  
  test -= w[i];
  sub1 = abs( test - (sum - test) );
  
  if(sub0 < sub1) printf("%d\n",sub0);
  else  printf("%d\n",sub1);   
  
  return 0;
}