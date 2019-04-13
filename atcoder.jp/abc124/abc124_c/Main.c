#include <stdio.h>

int main(void)
{
  int i = 0,a = 0,b = 0; 
  char S[100001];
  scanf("%s",S);
  for(i = 0;i < 100001;i++) {
    if(S[i] != '0' && S[i] != '1') break;
    if(i % 2 == 0) {
      if(S[i] != '0') a++;
      else if(S[i] != '1') b++;
    } else {
      if(S[i] != '1') a++;
      else if(S[i] != '0') b++;
    }  
  }
  if(a >= b) printf("%d",b);
  else printf("%d",a);
  return 0;
}