#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int i,N,K;
  scanf("%d %d",&N,&K);
  char a[N],b[N];
  scanf("%s",a);

  for(i = 0;i < N;i++) {
    b[i] = ' ';
    if(i + 1 == K) b[i] = tolower(a[i]);
    else b[i] = a[i];
    printf("%c",b[i]);
  }  

  printf("\n");
  return 0;
}