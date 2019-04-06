#include <stdio.h>

int main(void)
{
  int a[5],b[5],i = 0,mod = 10,ans = 0,buf = 0;
  for(i = 0;i < 5;i++) {
    scanf("%d",&a[i]);
    b[i] = a[i] % 10;
    if(b[i] > 0 && b[i] < mod) mod = b[i];
  }

  i = 0;
  for(i = 0;i < 5;i++) {
    buf = a[i] % 10;
    if(buf == 0) ans += ((a[i] / 10) + 0) * 10 ;
    else if(buf > 0) ans += ((a[i] / 10) + 1) * 10 ;
    //printf("%d\n",ans);
  }
  ans = ans - 10 + mod;

  printf("%d\n",ans);
  return 0;
}
