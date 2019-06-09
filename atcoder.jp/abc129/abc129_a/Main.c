#include <stdio.h>

int main(void)
{
  int t[3],i,j,min = 999999;
  scanf("%d %d %d\n",&t[0],&t[1],&t[2]);
  for(i = 0;i < 2;i++) {
    for(j = i + 1;j < 3;j++) {
      if(min > t[i] + t[j]) min = t[i] + t[j];
    }
  }
  printf("%d\n",min);
  return 0;
}