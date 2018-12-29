#include <stdio.h>

int main(void)
{
        int A,B,C,ans = 0;
        scanf("%d %d %d",&A,&B,&C);


        if(A + B + 1 >= C) {
                ans = C + B;
        } else {
                ans = B * 2 + A + 1;
        }

        printf("%d\n",ans);

        return 0;
}
