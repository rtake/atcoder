#include <stdio.h>

int main(void)
{
  int A,B;
  scanf("%d %d",&A,&B);
  if(A == B) printf("%d\n",2 * A);
  else if(A > B) printf("%d\n",2 * A - 1);
  else if(B > A) printf("%d\n",2 * B - 1);
  
  return 0;
}