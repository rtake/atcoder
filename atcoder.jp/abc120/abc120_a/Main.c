#include <stdio.h>

int main(void)
{
	int a,b,c,ans;
  	scanf("%d %d %d",&a,&b,&c);
	
  	if(c > b / a) {
    	ans = b / a;
    } else {
    	ans = c;
    }

	printf("%d\n",ans);
}