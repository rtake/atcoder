#include <stdio.h>
#include <string.h>

typedef struct R
{
  char s[11];
  int p;
} R;


int main(void)
{
  int i,j,N;
  scanf("%d",&N);
  R r[N];
  int ans[N];
  
  for(i = 0;i < N;i++) {
    scanf("%s %d",r[i].s,&r[i].p);
    ans[i] = i + 1;
  }  
    
  for(i = 0;i < N;i++) {
    int buf0;
    R buf1;
    for(j = 0;j < N - 1;j++) {
      if(strcmp(r[j].s,r[j + 1].s) > 0) {
        buf0 = ans[j];
        buf1 = r[j];
        ans[j] = ans[j + 1];
        r[j] = r[j + 1];
        ans[j + 1] = buf0;
        r[j + 1] = buf1;
      } else if(strcmp(r[j].s,r[j + 1].s) == 0) {
        if(r[j].p < r[j + 1].p) {
          buf0 = ans[j];
          buf1 = r[j];
          ans[j] = ans[j + 1];
          r[j] = r[j + 1];
          ans[j + 1] = buf0;
          r[j + 1] = buf1;
        }
      }  
    }
  }
  
  for(i = 0;i < N;i++) {
    printf("%d\n",ans[i]);
  }
  
  return 0;
}