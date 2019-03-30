#include <stdio.h>
#include <string.h>

int main(void)
{
  int N,i = 0,r = 0,b = 0;
  char s[256];
  scanf("%d",&N);
  scanf("%s",s);
  for(i=0;i<N;i++) {
    if(s[i] == 'R') r++;
    else if(s[i] == 'B') b++;
  }
  if(r > b) printf("Yes\n");
  else printf("No\n");

  return 0;
}
