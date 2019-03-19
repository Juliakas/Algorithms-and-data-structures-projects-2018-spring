#ifndef PQUEUE_H_INCLUDED
#define PQUEUE_H_INCLUDED

//266


//returned 0 - viskas ok
//returned 1 - nepriskyre atminties
//returned 2 - operuojama su tuscia eile

typedef struct Pqueue Pqueue;
typedef struct Node Node;
typedef int DataType;

struct Node{
    int data;
    int priority;
    struct Node* next;
};

struct Pqueue{
    Node* head;
    unsigned count;
};


Pqueue* Create();                   //sukuria nauja prioritetine eile
int IsEmpty(Pqueue* peil);          //jei sugrizta 0 tai ne tuscias, jei 1 tai tuscias
int IsFull();                       //jei sugrizta 0 tai ne pilnas, jei 1 tai pilnas
void InsertElement(DataType sk, int prior, Pqueue* peil);   //ideda nauja elementa
void PrintQueue(Pqueue* peil);              //atspausdina eile
DataType TakeElement(Pqueue* peil);         //isima elementa
void DeletePQueue(Pqueue* peil);             //sunaikina eile
DataType GetData(Pqueue* peil);             //gauna pirmo elemento data

#endif // PQUEUE_H_INCLUDED
