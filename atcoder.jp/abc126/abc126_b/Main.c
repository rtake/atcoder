#include <stdio.h>
#include <stdlib.h>

int chkdigit(int a,int b)
{  
  if(a == 0) {
    if(b == 0) return 0; // yy
    else if(b > 0 && b <= 9) return 1; // yy or mm 
  } else if(a == 1) {
    if(b > 3) return 0; // yy
    else if(b > 0 && b <= 2) return 1; // yy or mm
  } else if(a > 1) {
    return 0; // yy
  }
  
}


int main(void)
{
  char s[4],buf;
  int in,a[4],i;
  scanf("%s",s);
  
  for(i = 0;i < 4;i++) {
    buf = s[i];
    a[i] = atoi(&buf);
  }
  
  int c0,c1;
  c0 = chkdigit(a[0],a[1]);
  c1 = chkdigit(a[2],a[3]);
  
  if(c0 == 0 && c1 == 0) {
    printf("NA\n");
  } else if(c0 == 0 && c1 == 1) {
    printf("YYMM\n");
  } else if(c0 == 1 && c1 == 0) {
    printf("MMYY\n");  
  } else if(c0 == 1 && c1 == 1) {
    printf("AMBIGUOUS\n");
  }

  return 0;
}






