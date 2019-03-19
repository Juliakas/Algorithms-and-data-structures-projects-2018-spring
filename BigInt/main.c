#include "Arithmetic.h"
int main ()
{
    int error;
    char *input1 = "145009.0466198656\0";
    bigFloat fl = createBigFloat(&error, input1);
    bigInt a = createBigInt(&error, input1);
    char *input2 = "10\0";
    bigInt b = createBigInt(&error, input2);
    bigInt c = createBigInt(&error, "\0");
    big_divide(a, b, &c, &error);
    printList(c);
}
