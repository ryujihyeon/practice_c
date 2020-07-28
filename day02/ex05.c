#include <stdio.h>

int main()
{
    char _operation;
    int _a,_b;

    printf("input :");
    scanf("%d %c %d",&_a,&_operation,&_b);

    if ( _operation == '+'  )
    { //덧셈 
        /* code */
        printf("%d + %d = %d \n",_a,_b,_a+_b);
    }
    else if ( _operation == '-'  )
    { //덧셈 
        /* code */
        printf("%d - %d = %d \n",_a,_b,_a-_b);
    }
    else if ( _operation == '/'  )
    { //덧셈 
        /* code */
        printf("%d / %d = %d \n",_a,_b,_a/_b);
    }
    else if ( _operation == '*'  )
    { //덧셈 
        /* code */
        printf("%d * %d = %d \n",_a,_b,_a*_b);
    }
    else if ( _operation == '%'  )
    { //덧셈 
        /* code */
        printf("%d %c %d = %d \n",_a,37,_b,_a % _b);
    }
    else {
        printf("operation error \n");
    }

    return 0;
}