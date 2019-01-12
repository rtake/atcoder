#include <stdio.h>


int min(int p,int q)
{
        if(p >= q) {
                return q;
        } else {
                return p;
        }
}

int main(void)
{
        int i,n,a,b;
        scanf("%d",&n);
        scanf("%d %d",&a,&b);

        int counta = 0,countb = 0,countc = 0;
        int p[n];
        for(i = 0;i < n;i++) {
                scanf("%d",&p[i]);

                if(p[i] <= a) {
                        counta++;
                } else if(p[i] > a && p[i] <= b) {
                        countb++;
                } else if(p[i] > b) {
                        countc++;
                }

        }


        printf("%d\n",min(min(counta,countb),countc));

        return 0;
}
