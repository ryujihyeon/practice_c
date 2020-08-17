#include "yasML/yasML.h"

int main()
{
    Matrix *m1;

    m1 = identity(3);
    scalar_multiply(m1,7);

    print(m1);

    free(m1);
}