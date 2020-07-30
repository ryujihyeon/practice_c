#include <stdio.h>

int _sum(int value1,int value2)
{
    int result = value1 + value2;
    return result;
}

void _test()
{
    printf("test call 1 \n");
    return;
    printf("test call 2 \n");
}

void main()
{
    // call _sum pass 2 , 3 
    int _value = _sum(2,3);
    printf("hello world %d \n",_value);

    _test();
}

/*

10 LET A=1
15 A = A+1
20 PRINT A
25 IF A > 10 THEN GOTO 40
30 GOTO 15
40 PRINT "END"

RUN 10


*/