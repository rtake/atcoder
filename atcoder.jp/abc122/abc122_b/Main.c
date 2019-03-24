#include <stdio.h>
#include <string.h>

int check_atcg(char c)
{
  if(c == 'A' || c == 'T' || c == 'C' || c == 'G') {
    return 1;
  }

  return 0;
}

int main(void)
{
  int i = 0,len = 0,maxlen = 0;
  char S[10];
  scanf("%s",S);

  for(i = 0;i < strlen(S);i++) {
    //printf("%c\n",S[i]);

    while(check_atcg(S[i]) == 1) {
      //printf("len %d\n",len);
      len++;
      i++;
    }

  if(len > maxlen) maxlen = len;

  len = 0;

  }

  printf("%d\n",maxlen);

  return 0;
}
