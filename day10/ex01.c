#include <stdio.h>

int main()
{
  int data[2] = {0x12345678,0x12345678,0x12345678};

  // data[0] = 0x00;
  *(char *)(data+0) = 0x00;
  printf("%8x\n",data[0]);

  //data[1]
  *( (char *)data + 6) = 0x00;
  printf("%8x\n",data[1]);

  return 0;
}