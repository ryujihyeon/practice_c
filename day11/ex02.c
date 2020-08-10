#include <stdio.h>

int main()
{
  int **pp;
  int data = 3;

  int *p;

  p = &data;
  pp = &p;
  // pp = &&data;
  // pp = (int **)&data;

  printf("%d \n",**pp);

}