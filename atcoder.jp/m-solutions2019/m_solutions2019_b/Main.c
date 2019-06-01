#include <stdio.h>
#include <string.h>

int main(void)
{
  int i,o = 0,x = 0;
  char s[16];
  scanf("%s",s);
  for(i = 0;i < strlen(s);i++) {
    if(s[i] == 'o') o++;
    else if(s[i] == 'x') x++;
  }

  if((15 - strlen(s)) + o >= 8) printf("YES\n");  
  else printf("NO\n"); 
  
  return 0;
}