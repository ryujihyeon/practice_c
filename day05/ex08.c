#include <stdio.h>

int main()
{
    int data = 0;

    //if(data = 3) //무조건 참이면서 값이 새로 써짐 
    if( 3 == data) //오류를 줄이는 코딩 방식
    {
        printf("data equal to 3 \n");
    }


    printf("complete %d \n",data);

    return 1;
}