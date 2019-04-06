#include <stdio.h>

int main(void)
{
  int a[10],i = 0,k,j = 0;
  for(i = 0;i < 5;i++) {
    scanf("%d",&a[i]);
  }
  scanf("%d",&k);

  i = 0;
  for(i = 0;i < 4;i++) {
    j = 0;
    for(j = i + 1;j <5;j++) {
      if(a[j] - a[i] > k) {
        printf(":(\n");
        return 0;
      }
    }
  }
  printf("Yay!\n");
  return 0;
}
