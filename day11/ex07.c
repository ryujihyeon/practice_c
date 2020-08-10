#include <stdio.h>
#include <malloc.h>

typedef unsigned int UInt;
typedef unsigned char Uchar;
typedef Uchar * PTRchar;

typedef int MyData[5];

int main()
{
  //  d[5] = {1,2,3,4,5};
  unsigned int a = 1;
  UInt b =2;
  Uchar c = 128;
  //char *ptr;
  PTRchar ptr;
  ptr = &c;
  MyData _p = {1,2,3,4,5};
  printf("%d %d %d %d %d\n",a,b,c,*ptr,_p[0]);

  MyData *p;
  p = (MyData *)malloc(sizeof(MyData));
  (*p)[0] = 3;
  printf("%d \n",(*p)[0]);

  
}