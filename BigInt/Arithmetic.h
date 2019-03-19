#ifndef KETVIRTA_ARITHMETIC_H
#define KETVIRTA_ARITHMETIC_H
#include "bigint.h"

bigInt createBigInt(int *, char *);
bigFloat createBigFloat(int *, char *);
void big_add(bigInt, bigInt, bigInt *, int *); //Jei truksta pirmo arba antro saraso error = 1
void big_subtract(bigInt, bigInt, bigInt *, int *); //Jei truksta pirmo arba antro saraso error = 1, jei bandoma atimti is mazesnio didesni error = 3
void big_multiply(bigInt, bigInt, bigInt *, int *); //Jei truksta pirmo arba antro saraso error = 1
void big_divide(bigInt, bigInt, bigInt *, int *); //Jei truksta pirmo arba antro saraso error = 1, jei dalyba is nulio error = 2;

//Jei viskas gerai ivyksta error = 0;

#endif //KETVIRTA_ARITHMETIC_H
