#include <stdio.h>
#include <stdlib.h>

int main(void)
{
      int n,h,w,i = 0,j = 0;
      scanf("%d %d %d",&n,&h,&w);
//      printf("%d\n",n);
      int a[n],b[n];      

      for(i=0;i < n;i++) {
            scanf("%d %d",&a[i],&b[i]);
//            printf("%d %d\n",a[i],b[i]);

            if(a[i] >= h && b[i] >= w) {
//                  printf("ok\n");
                  j++;
            }

      }

      printf("%d\n",j);

      return 0;
}