#include<stdio.h>

int main(void)
{
        int n,k,ans;
        scanf("%d %d",&n,&k);

        if(n % 2 == 0 && n / 2  >= k) {
                printf("YES\n");
        } else if(n % 2 == 1 && n / 2 + 1 >= k) {
                printf("YES\n");
        } else {
                printf("NO\n");
        }

        return 0;
}
