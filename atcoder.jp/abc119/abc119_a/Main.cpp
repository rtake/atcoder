#include <cstdio>

using namespace std;

int main(void)
{
  int y,m,d;
  scanf("%d/%d/%d",&y,&m,&d);
  
  if(y > 2019) {
    printf("TBD\n");
  } else if(y < 2019) {  
    printf("Heisei\n");
  } else {
    
    if(m > 4) {
      printf("TBD\n");
    } else if(m <= 4) {
      printf("Heisei\n");
    }
  
  }
  
  return 0;
}

