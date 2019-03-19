#ifndef KETVIRTA_BIGINT_H
#define KETVIRTA_BIGINT_H

struct Element {
    struct Element *forw, *backw;
    int data;
};

typedef struct Element Big_int;
typedef Big_int* bigInt;

struct Big_float {
    bigInt head;
    int floatPoint;
};
typedef struct Big_float bigFloat;

//bigint.c
bigInt getTail(bigInt);
int printList(bigInt);
int deleteList(bigInt*);
int getListSize(bigInt);
int checkIfNumber(const char *);
void swapPtr(bigInt*, bigInt*);
void insertBegin(bigInt*, int);
void deleteFirstElement(bigInt*);
void copyList(bigInt, bigInt*);

//Sumavimo funkcijos

int sum(Big_int*, Big_int*, Big_int**);
int subtraction(Big_int*, Big_int*, Big_int**);
int multiplication(Big_int*, Big_int*, Big_int**);
int division(Big_int*, Big_int*, Big_int**);

#endif //KETVIRTA_BIGINT_H
