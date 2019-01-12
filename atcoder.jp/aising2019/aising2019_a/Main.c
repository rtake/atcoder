#include <stdio.h>

int main(void)
{
  int n,h,w;
	scanf("%d",&n);
	scanf("%d",&h);
    scanf("%d",&w);
  
	printf("%d\n",(n-h+1)*(n-w+1));

}