#include <stdio.h>

int main(void)
{
  char b;
  scanf("%c",&b);

  if(b == 'A') {
    printf("T\n");
  } else if(b == 'C') {
    printf("G\n");
  } else if(b == 'G') {
    printf("C\n");
  } else if(b == 'T') {
    printf("A\n");
  }

  return 0;
}
