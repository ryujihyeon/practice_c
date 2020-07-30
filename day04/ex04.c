#include <stdio.h>

int _sum(int value1,int value2);
int _mul(int value1,int value2);

int main()
{
    int rest = _sum(2,3);
    int rest2 = _mul(2,3);
    printf("result sum %d \n",rest);
    printf("result mul %d \n",rest2);


    return 1;
}