# include <stdio.h>
# include <string.h>

int main(void) {
  char s[256];
  scanf( "%s", s);
  if( strstr( s, "ABC") ) { printf( "ARC\n" ); }
  else if( strstr( s, "ARC") ) { printf( "ABC\n" ); }
}