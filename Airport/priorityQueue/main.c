#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

int main()
{

    Pqueue* a = Create();

    IsEmpty(a);
    IsFull();

    InsertElement(1, 1, a);
    InsertElement(2, 2, a);
    InsertElement(3, 3, a);
    InsertElement(5, 5, a);
    InsertElement(2, 2, a);
    PrintQueue(a);

    printf("Istrauktas elementas: %d \n", TakeElement(a));
    PrintQueue(a);

    IsEmpty(a);
    IsFull();

    printf("Istrauktas elementas: %d \n", TakeElement(a));

    PrintQueue(a);
    InsertElement(10, 10, a);
    InsertElement(7, 7, a);
    printf("Pirmo elemento reiksme: %d \n", GetData(a));
    PrintQueue(a);

    DeletePQueue(a);
    PrintQueue(a);

    return 0;
}
