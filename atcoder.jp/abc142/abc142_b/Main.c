#include <stdio.h>

int main(void)
{
  int n,k,ans = 0;
  scanf("%d %d",&n,&k);
  int i,h[n];
  for(i = 0;i < n;i++) scanf("%d",&h[i]);
  for(i = 0;i < n;i++) {
    if(h[i] >= k) ans++;
  }
    
  printf("%d\n",ans);
  
  return 0;
}
