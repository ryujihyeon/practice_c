#include <stdio.h>

// void _test(char *strMsg);
void _test(char *);

void main()
{
    _test("hi ~");
}


void _test(char *strMsg)
{
    printf("test call 1 %s \n",strMsg);
}
