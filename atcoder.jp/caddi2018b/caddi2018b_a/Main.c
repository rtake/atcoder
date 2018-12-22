#include <stdio.h>
#include <stdlib.h>

int main(void)
{
      int a,i,b,j = 0;
      char r[256];
      scanf("%s",r);

      for(i=0;i<4;i++) {

            if(r[i] == '2')  j++;

      }

      printf("%d\n",j);

      return 0;
}