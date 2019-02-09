#include<stdio.h>

int main(void)
{
        int a[3],b[3],c[10],i = 0;

        for(i = 0;i < 3;i++) {
                scanf("%d %d",&a[i],&b[i]);
        }

        i = 0;
        for(i = 0;i < 10;i++) {
                c[i] = 0;
        }

        i = 0;
        for(i = 0;i < 3;i++) {
                c[a[i]]++;
                c[b[i]]++;

                if(c[a[i]] > 2 || c[b[i]] > 2) {
                        printf("NO\n");
                        break;
                }

                if(i == 2) {
                        printf("YES\n");
                        break;
                }

        }

        return 0;
}
