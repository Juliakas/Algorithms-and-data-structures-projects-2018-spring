#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"
#include "Arithmetic.h"

bigInt createBigInt(int *error, char *number)
{
    int index = 1;
    Big_int *head, *elem, *prev;
    if(checkIfNumber(number) == 0)
    {
        *error = 1;
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
    *error = 0;
    return head;
}

bigFloat createBigFloat(int *error, char *number)
{
    bigFloat flt;
    int index = 0;
    int beforeFlt;
    for(;number[index] != '\0'; index++)
    {
        if(number[index] == '.')
        {
            break;
        }
    }
    for(; )
    createBigInt(error, number);
}

void big_add(bigInt head1, bigInt head2, bigInt *answer, int *error)
{
    if((*answer) != NULL)
        deleteList(answer);
    *error = sum(head1, head2, answer);
}
void big_subtract(bigInt head1, bigInt head2, bigInt *answer, int *error)
{
    if((*answer) != NULL)
        deleteList(answer);
    *error = subtraction(head1, head2, answer);
}
void big_multiply(bigInt head1, bigInt head2, bigInt *answer, int *error)
{
    if((*answer) != NULL)
        deleteList(answer);
    *error = multiplication(head1, head2, answer);
}
void big_divide(bigInt head1, bigInt head2, bigInt *answer, int *error)
{
    if((*answer) != NULL)
        deleteList(answer);
    *error = division(head1, head2, answer);
}
