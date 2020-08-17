#include <stdio.h>

int main()
{
  //상위 2바이트 하위2바이트를 short 형으로 구한뒤 두수를 더하시오.
  int a = 0x00030002;
  short *p = (short *)&a;

  short b = *p;
  short c = *(p+1);
  printf("%08x + %08x = %08x\n",b,c,b+c);

  printf("%08x %08x \n",*((short *)&a), *(((short *)&a)+1) );

  return 0;
}
