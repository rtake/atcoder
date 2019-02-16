#include <stdio.h>

int main(void)
{
	int a,b;
	scanf("%d %d",&a,&b);  

  	if(b % a == 0) printf("%d\n",a + b);
  	else printf("%d\n",b - a);

	return 0;
}  