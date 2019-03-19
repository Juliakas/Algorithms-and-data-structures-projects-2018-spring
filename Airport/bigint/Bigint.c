#include <stdio.h>
#include <stdlib.h>
#include "Bigint.h"

int checkIfNumber(const char *string) // Grazins ar paduotas skaicius sudarytas is skaitmenu
{
    int index = 0;
    const int zero = '0', nine = '9';
    for(;string[index] != '\0'; index++)
        if(string[index] < zero || string[index] > nine) return 0;
    return 1;
}
void insertBegin(Big_int **head, int temp) // iterpiam elementa(char) listo pradzioje
{
    Big_int *elem;
    elem = (Big_int*) malloc(sizeof(Big_int));
    elem -> data = temp;
    elem -> forw = *head;
    elem -> backw = NULL;
    (*head) -> backw = elem;
    *head = elem;
}
Big_int *getTail(Big_int *head)
{
    while(head -> forw != NULL)
    {
        head = head -> forw;
    }
    return head;
}
int printList(Big_int *head)
{
    if (head == NULL)
    {
        return 1;
    }
    while (head != NULL)
    {
        printf("%d", head -> data);
        head = head -> forw;
    }
    return 0;
}
void copyList(Big_int* head, Big_int** newHead)
{
    *newHead = (Big_int*)malloc(sizeof(Big_int));
    (*newHead) -> backw = NULL;
    (*newHead) -> forw = NULL;
    (*newHead) -> data = head -> data;
    Big_int *prev = *newHead;
    Big_int *elem;
    head = head -> forw;
    while(head != NULL)
    {
        elem = (Big_int*)malloc(sizeof(Big_int));
        prev -> forw = elem;
        elem -> backw = prev;
        elem -> forw = NULL;
        elem -> data = head -> data;
        prev = elem;
        head = head -> forw;
    }
}
void deleteFirstElement(Big_int **head)
{
    Big_int *elem;
    elem = *head;
    if((*head) -> forw != NULL)
    {
        *head = (*head)->forw;
        (*head)->backw = NULL;
    }
    else *head = NULL;
    free(elem); // atlaisvinam atminti
}
void swapPtr(Big_int **ptr1, Big_int **ptr2)
{
    Big_int *temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int getListSize(Big_int *head)
{
    int size = 0;
    while(head != NULL)
    {
        size++;
        head = head -> forw;
    }
    return size;
}
int deleteList(Big_int **head)
{
    Big_int *elem;
    if (*head != NULL)
    {
        while ((*head) != NULL)
            deleteFirstElement(head);
        *head = NULL;
        return 1;
    }
    else return 0;
}
int multiplication(Big_int *head1, Big_int *head2, Big_int **finalAnswer)
{
    Big_int *temp, *one;
    if(head1 == NULL || head2 == NULL) return 1;                          //Nėra duomenų
    one = (Big_int*)malloc(sizeof(Big_int));
    one -> forw = NULL;
    one -> backw = NULL;
    one -> data = 1;
    *finalAnswer = (Big_int*)malloc(sizeof(Big_int));
    (*finalAnswer) -> forw = NULL;
    (*finalAnswer) -> backw = NULL;
    (*finalAnswer) -> data = 0;
    Big_int *backup;
    copyList(head2, &backup);
    while(subtraction(head2, one, &head2) != 3)
    {
        sum(*finalAnswer, head1, &temp);
        deleteList(finalAnswer);
        *finalAnswer = temp;
    }
    deleteList(&head2);
    copyList(backup, &head2);
    deleteList(&one);
    return 0;
}
int division(Big_int *head1, Big_int *head2, Big_int **finalAnswer)
{
    Big_int *temp, *one;
    if(head1 == NULL || head2 == NULL) return 1;                          //Nėra duomenų
    if(head2 -> data == 0 && head2 -> forw == NULL) return 2;             //Dalyba iš 0
    one = (Big_int*)malloc(sizeof(Big_int));
    one -> data = 1;
    one -> forw = NULL;
    one -> backw = NULL;
    *finalAnswer = (Big_int*)malloc(sizeof(Big_int));
    (*finalAnswer) -> data = 0;
    (*finalAnswer) -> forw = NULL;
    (*finalAnswer) -> backw = NULL;
    Big_int *backup;
    copyList(head1, &backup);
    while(subtraction(head1, head2, &temp) != 3)
    {
        deleteList(&head1);
        head1 = temp;
        sum(*finalAnswer, one, &temp);
        deleteList(finalAnswer);
        *finalAnswer = temp;
    }
    deleteList(&head1);
    copyList(backup, &head1);
    deleteList(&one);
    return 0;
}
int sum(Big_int *head1, Big_int *head2, Big_int **finalAnswer)
{
    if(head1 == NULL || head2 == NULL)
        return 1;                       //Trūksta pirmo arba antro sąrašo
    if(getListSize(head2) > getListSize(head1)) swapPtr(&head1, &head2);
    Big_int *tail1 = getTail(head1);
    Big_int *tail2 = getTail(head2);
    int carry, temp;
    Big_int *tempTail;
    copyList(head1, finalAnswer);
    Big_int *tail3 = getTail(*finalAnswer);
    while(tail2 != NULL)
    {
        carry = (tail3 -> data + tail2 -> data) / 10;
        tail3 -> data = (tail3 -> data + tail2 -> data) % 10;
        tail3 = tail3 -> backw;
        tail2 = tail2 -> backw;
        tempTail = tail3;
        while(carry == 1)
        {
            if(tempTail == NULL)
            {
                insertBegin(finalAnswer, 0);
                tempTail = *finalAnswer;
            }
            temp = (tempTail -> data + carry) / 10;
            tempTail -> data = (tempTail -> data + carry) % 10;
            carry = temp;
            tempTail = tempTail -> backw;
        }
    }
    return 0;
}
int subtraction(Big_int *head1, Big_int *head2, Big_int **finalAnswer) {
    if (head1 == NULL || head2 == NULL) {
        return 1;
    }
    if (getListSize(head2) > getListSize(head1)) {
        return 3;
    }
    else if(getListSize(head2) == getListSize(head1))
    {
        Big_int *elem1 = head1, *elem2 = head2;
        while(elem1 != NULL)
        {
            if(elem2 -> data > elem1 -> data)
                return 3;
            if(elem1 -> data > elem2 -> data)
                break;
            elem1 = elem1 -> forw;
            elem2 = elem2 -> forw;
        }
    }
    Big_int *tail2 = getTail(head2);
    int carry, temp;
    Big_int *elem;
    copyList(head1, finalAnswer);
    Big_int *tail3 = getTail(*finalAnswer);
    while (tail2 != NULL) {
        carry = (tail3->data - tail2->data + 10) / 10;
        if(carry == 1) carry = 0;
        else carry = 1;
        tail3->data = (tail3->data - tail2->data + 10) % 10;
        tail3 = tail3->backw;
        tail2 = tail2->backw;
        elem = tail3;

        while (carry == 1) {
            temp = (elem->data - carry + 10) / 10;
            elem->data = (elem->data - carry + 10) % 10;
            carry = temp;
            if(carry == 1) carry = 0;
            else carry = 1;
            elem = elem->backw;
        }
    }
    elem = *finalAnswer;
    while(elem -> data == 0 && elem -> forw != NULL)
    {
        deleteFirstElement(finalAnswer);
        elem = *finalAnswer;
    }
    return 0;
}
