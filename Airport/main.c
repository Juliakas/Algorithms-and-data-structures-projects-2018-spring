#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "priorityQueue/pqueue.h"
#include "bigint/Arithmetic.h"

void simulation(bigInt, bigInt, int, double, bigInt *, bigInt *, bigInt *, bigInt *);
void reduceByOne(Pqueue *);
void addValues(Pqueue *, int, bigInt *, bigInt *, bigInt *, bigInt *);
void deleteBigInt(bigInt *oldBigInt);
void printResults(bigInt, bigInt, bigInt, bigInt);
void printBigInt(bigInt);
void increaseHeadPriority(Pqueue *);
bool hasPlaneFallen(Pqueue *);
char* intToString(int integer);

int main() {

    bigInt ARRIVAL_TIME = createBigInt("20\0");
    bigInt DEPARTURE_TIME = createBigInt("15\0");
    const int FUEL_TIME = 150;
    const double PROBABILITY = 0.03;

    bigInt maxAT = createBigInt("0\0"), maxDT = createBigInt("0\0"); //maximum time
    bigInt avgAT = createBigInt("0\0"), avgDT = createBigInt("0\0"); //average time

    simulation(ARRIVAL_TIME, DEPARTURE_TIME, FUEL_TIME, PROBABILITY, &maxAT, &maxDT, &avgAT, &avgDT);
    printResults(maxAT, maxDT, avgAT, avgDT);

    return 0;
}

void simulation(bigInt ARRIVAL_TIME, bigInt DEPARTURE_TIME, const int FUEL_TIME, const double PROBABILITY,
                bigInt *maxAT, bigInt *maxDT, bigInt *avgAT, bigInt *avgDT) {
    bigInt insAT = createBigInt("0\0"), insDT = createBigInt("0\0"); //instances
    bigInt allAT = createBigInt("0\0"), allDT = createBigInt("0\0"); //total time
    bigInt one = createBigInt("1\0");
    bigInt zero = createBigInt("0\0");
    bigInt remainingTime = createBigInt("0\0");
    bool planeFell = false;
    srand((unsigned) time(NULL));
    Pqueue *planeQueue = Create();
    while(!planeFell) {
        if(rand() % RAND_MAX < (int)(RAND_MAX * PROBABILITY)) {
            if(rand() % 2) {
                InsertElement(FUEL_TIME, 1, planeQueue);
                big_add(insAT, one, &insAT);
                printf("A plane is waiting to land\n");
            } else {
                InsertElement(0, 0, planeQueue);
                big_add(insDT, one, &insDT);
                printf("A plane is waiting for departure\n");
            }
        }
        addValues(planeQueue, FUEL_TIME, &allAT, &allDT, maxAT, maxDT);
        if(big_subtract(remainingTime, one, &remainingTime) != 3 && !IsEmpty(planeQueue)) {
            if (big_subtract(remainingTime, one, &remainingTime) == 3) {
                TakeElement(planeQueue);
                if(!IsEmpty(planeQueue)) {
                    Node *node = planeQueue->head;
                    if (node->priority == 2) printf("A plane has departed\n");
                    else if (node->priority == 3) printf("A plane has arrived\n");
                }
            }
            else big_add(remainingTime, one, &remainingTime);
        }
        if(big_subtract(remainingTime, one, &remainingTime) == 3) {
            if(!IsEmpty(planeQueue))
                if(GetData(planeQueue) <= 0) {
                    printf("Next plane is departing\n");
                    big_add(DEPARTURE_TIME, zero, &remainingTime);
                } else {
                printf("Next plane is arriving\n");
                big_add(ARRIVAL_TIME, zero, &remainingTime);
                }
        } else big_add(remainingTime, one, &remainingTime);
        reduceByOne(planeQueue);
        if(!IsEmpty(planeQueue)) increaseHeadPriority(planeQueue);
        planeFell = hasPlaneFallen(planeQueue);
    }
    printf("\n\n!!!!!!!A plane has fallen!!!!!!!\n\n");
    big_divide(allAT, insAT, avgAT);
    big_divide(allDT, insDT, avgDT);
    deleteBigInt(&insAT);
    deleteBigInt(&insDT);
    deleteBigInt(&allAT);
    deleteBigInt(&allDT);
    deleteBigInt(&one);
    deleteBigInt(&zero);
    deleteBigInt(&remainingTime);
    DeletePQueue(planeQueue);
}

void printResults(bigInt maxAT, bigInt maxDT, bigInt avgAT, bigInt avgDT) {
    printf("Maximum arrival time: "); printBigInt(maxAT); printf("\n");
    printf("Maximum departure time: "); printBigInt(maxDT); printf("\n");
    printf("Average arrival time: "); printBigInt(avgAT); printf("\n");
    printf("Average departure time: "); printBigInt(avgDT); printf("\n");
}

void reduceByOne(Pqueue *planeQueue) {
    if(IsEmpty(planeQueue)) return;
    Node *node = planeQueue -> head;
    while(node != NULL) {
        node -> data -= 1;
        if(node -> priority == 1 || node -> priority == 3) {
            printf("%d  ", node -> data);
        }
        node = node -> next;
    }
    printf("\n");
}

bool hasPlaneFallen(Pqueue *planeQueue) {
    if(IsEmpty(planeQueue)) return false;
    Node *node = planeQueue -> head;
    while(node != NULL) {
        if((node -> priority == 1 || node -> priority == 3) && node -> data == 0) return true;
        node = node -> next;
    }
    return false;
}

void addValues(Pqueue *planeQueue, int FUEL_TIME, bigInt *allAT, bigInt *allDT, bigInt *maxAT, bigInt *maxDT) {
    if(IsEmpty(planeQueue)) return;
    bigInt one = createBigInt("1\0");
    bigInt t;
    char *string;
    Node *node = planeQueue -> head;
    while(node != NULL) {
        if(node -> data > 0) {
            big_add(*allAT, one, allAT);
            string = intToString(FUEL_TIME - (node -> data));
            t = createBigInt(string);
            if(big_subtract(*maxAT, t, &t) == 3) {
                deleteBigInt(maxAT);
                *maxAT = createBigInt(string);
            }
        }
        else {
            big_add(*allDT, one, allDT);
            string = intToString(-(node -> data));
            t = createBigInt(string);
            if(big_subtract(*maxDT, t, &t) == 3) { //Jeigu 3, maxDT < t
                deleteBigInt(maxDT);
                *maxDT = createBigInt(string);
            }
        }
        free(string);
        deleteBigInt(&t);
        node = node -> next;
    }
    deleteBigInt(&one);
}

char *intToString(int integer) {
    int decimalCounter = 1;
    int decimal = integer;
    char *string;
    do {
        decimal /= 10;
        decimalCounter++;
    } while(!decimal == 0);
    string = (char*)malloc(decimalCounter * sizeof(char));
    for(int index = decimalCounter - 2; index >= 0; index--) {
        string[index] = (char)((integer % 10) + 48);
        integer /= 10;
    }
    string[decimalCounter - 1] = '\0';
    return string;
}

void deleteBigInt(bigInt *oldBigInt) {
    bigInt temp;
    while(*oldBigInt != NULL) {
        temp = (*oldBigInt) -> forw;
        free(*oldBigInt);
        *oldBigInt = temp;
    }
}

void printBigInt(bigInt bint) {
    while(bint != NULL) {
        printf("%d", bint -> data);
        bint = bint -> forw;
    }
}

void increaseHeadPriority(Pqueue *planeQueue) {
    Node *node = planeQueue -> head;
    if(node -> priority == 0) node -> priority = 2;
    else if(node -> priority == 1) node -> priority = 3;
}
