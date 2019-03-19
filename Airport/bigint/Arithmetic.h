#ifndef KETVIRTA_ARITHMETIC_H
#define KETVIRTA_ARITHMETIC_H
#include "Bigint.h"

bigInt createBigInt(char *);
int big_add(bigInt, bigInt, bigInt *); //Jei truksta pirmo arba antro saraso error = 1
int big_subtract(bigInt, bigInt, bigInt *); //Jei truksta pirmo arba antro saraso error = 1, jei bandoma atimti is mazesnio didesni error = 3
int big_multiply(bigInt, bigInt, bigInt *); //Jei truksta pirmo arba antro saraso error = 1
int big_divide(bigInt, bigInt, bigInt *); //Jei truksta pirmo arba antro saraso error = 1, jei dalyba is nulio error = 2;

//Jei viskas gerai ivyksta error = 0;

#endif //KETVIRTA_ARITHMETIC_H
