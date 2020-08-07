#include <stdio.h>

int main()
{
  char data[5]={'a','b','c','d','e'};

  char *p = data;

  printf("%c %c %c %c\n",*p,*(p+1),*(data+2),p[3] );

  p = p + 1;
  // data = data + 1; //read only address
  printf("%c %c \n",*p,data);

  return 1;
}