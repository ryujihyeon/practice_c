#include <stdio.h>

int main()
{
    //지수형 표현 
    float a = 1.52e-5;
    int _b = 0xFA;
    int _c = 012;
    int _d = 0b10011000;
    char *strMsg = "hello world";

    printf("%f %d %d %d %s\n",a,_b,_c,_d,strMsg);
    

    return 0;
}