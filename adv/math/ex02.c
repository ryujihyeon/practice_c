#include "yasML/yasML.h"

int main()
{
    Matrix *m1, *m2;

    m1 = constructor(3, 2);

    m1->numbers[0][0] = 1;
    m1->numbers[1][0] = 2;

    m1->numbers[0][1] = 3;
    m1->numbers[1][1] = 4;

    m1->numbers[0][2] = 5;
    m1->numbers[1][2] = 6;

    m2 = constructor(2, 3);

    m2->numbers[0][0] = 1;
    m2->numbers[1][0] = 2;
    m2->numbers[2][0] = 3;

    m2->numbers[0][1] = 4;
    m2->numbers[1][1] = 5;
    m2->numbers[2][1] = 6;

    print(m1);
    print(m2);

    Matrix *m3 = multiply(m1, m2);
    
    print(m3);

//add
    Matrix *m4 = identity(2);
    Matrix *m5 = identity(2);

    add(m4,m5);

    print(m4);



    free(m1);
    free(m2);
    free(m3);
    free(m4);
    free(m5);
}