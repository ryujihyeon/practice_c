#include "yasML/yasML.h"

int main()
{
    Matrix *m1;
   
    m1 = identity(2);
    
    print(m1);
   
    free(m1);
}