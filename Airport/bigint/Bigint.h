#ifndef KETVIRTA_BIGINT_H
#define KETVIRTA_BIGINT_H

struct Element {
    struct Element *forw, *backw;
    int data;
};

typedef struct Element Big_int;
typedef Big_int* bigInt;

//bigint.c
bigInt getTail(Big_int *);
int printList(Big_int *);
int deleteList(Big_int **);
int getListSize(Big_int *);
int checkIfNumber(const char *);
void swapPtr(Big_int **, Big_int **);
void insertBegin(Big_int **, int);
void deleteFirstElement(Big_int **);
void copyList(Big_int *, Big_int **);

//Sumavimo funkcijos

int sum(Big_int*, Big_int*, Big_int**);
int subtraction(Big_int*, Big_int*, Big_int**);
int multiplication(Big_int*, Big_int*, Big_int**);
int division(Big_int*, Big_int*, Big_int**);

#endif //KETVIRTA_BIGINT_H
