#include <stdio.h>
#include <stdlib.h>
#include "Bigint.h"
#include "Arithmetic.h"

bigInt createBigInt(char *number)
{
    int index = 1;
    Big_int *head, *elem, *prev;
    if(checkIfNumber(number) == 0)
    {
        return NULL;
    }                       //Įvestas nelegalus simbolis
    head = (Big_int*)malloc(sizeof(Big_int));
    head -> backw = NULL;
    head -> forw = NULL;
    head -> data = (int)number[0] - 48;
    while(number[index] != '\0')
    {
        if(index == 1) prev = head;
        else prev = elem;
        elem = (Big_int*)malloc(sizeof(Big_int));
        prev -> forw = elem;
        elem -> backw = prev;
        elem -> forw = NULL;
        elem -> data = (int)number[index] - 48;    // '0' = 48;
        index ++;
    }
    return head;
}
int big_add(bigInt head1, bigInt head2, bigInt *answer)
{
    if((*answer) != NULL && (*answer) != head1 && (*answer) != head2)
        deleteList(answer);
    return sum(head1, head2, answer);
}
int big_subtract(bigInt head1, bigInt head2, bigInt *answer)
{
    if((*answer) != NULL && (*answer) != head1 && (*answer) != head2)
        deleteList(answer);
    return subtraction(head1, head2, answer);
}
int big_multiply(bigInt head1, bigInt head2, bigInt *answer)
{
    if((*answer) != NULL && (*answer) != head1 && (*answer) != head2)
        deleteList(answer);
    return multiplication(head1, head2, answer);
}
int big_divide(bigInt head1, bigInt head2, bigInt *answer)
{
    if((*answer) != NULL && (*answer) != head1 && (*answer) != head2)
        deleteList(answer);
    return division(head1, head2, answer);
}
