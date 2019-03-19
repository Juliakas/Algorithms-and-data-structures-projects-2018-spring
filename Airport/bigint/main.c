#include "Arithmetic.h"
int main ()
{
    int error;
    char *input1 = "616515113513\0";
    bigInt a = createBigInt(&error, input1);
    char *input2 = "13156\0";
    bigInt b = createBigInt(&error, input2);
    bigInt c = createBigInt(&error, "\0");
    big_divide(a, b, &c, &error);
    printList(c);
}
