#include <stdio.h>

int main(void)
{
        int n,m,i = 0,j = 0,k = 0,a,ans = 0;
        scanf("%d %d",&n,&m);
        int M[m];

        for(i = 0;i < m;i++) {
                M[i] = 0;
        }

        i = 0;
        for(i = 0;i < n;i++) {
                scanf("%d",&k);
                j = 0;

                for(j = 0;j < k;j++) {
                        scanf("%d",&a);
                        M[a - 1]++;
                }

        }

        i = 0;
        for(i = 0;i < m;i++) {

                if(M[i] == n) ans++;

        }
        printf("%d\n",ans);
        return 0;
}
