#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"


Pqueue* Create()                //funkcija prioritetines eiles sukurimui
{
    Pqueue* peil = (Pqueue*) calloc(1, sizeof(Pqueue));

    if(peil == NULL)
    {
        exit(1);
    }
    return peil;
}


int IsEmpty(Pqueue* peil)          //funkcija kuri tikrina ar eile yra tuscia
{
    if(peil->count == 0)
    {
        return 1; //jei tuscias
    }
    else
    {
        return 0; //ne tuscias
    }

}


int IsFull()                   //funkcija kuri tikraina ar eile yra pilna
{
    Node* t = (Node*) malloc(sizeof(Node));

    if(t == NULL)
    {
        return 1; //jei pilnas
    }
    else
    {
        return 0; //jei nepilnas
    }
    free(t);
}

void InsertElement(int sk, int prior, Pqueue* peil)     //funkcija skirta naujo elemnto idejimui i eile
{
    Node* p;
    Node* n = (Node*) malloc(sizeof(Node));

    if(n == NULL)
    {
        exit(1);                        //jei nebera laisvos atminties
    }

    if(peil->count == 0)                //jei pirmas elementas
    {
        n->data = sk;
        n->priority = prior;
        n->next = peil->head;
        peil->head = n;
        peil->count++;
    }
    else
    {
       p = peil->head;
        if(p->priority < prior)
        {
            n->data = sk;
            n->priority = prior;
            n->next = peil->head;
            peil->head = n;
            peil->count++;
        }
        else
        {
        while(p->next!= NULL && p->next->priority >= prior)
        {
            p= p->next;
        }
        n->data = sk;
        n->priority = prior;

        n->next = p->next;
        p->next = n;
        peil->count++;
        }
    }
}


void PrintQueue(Pqueue* peil)       //funkcija spausdinanti prioritetine eile
{
    Node* n = peil->head;

    if(peil->count == 0)
    {
        exit(2);
    }
    else
    {
        printf("Prioritetine eile: ");
        while(n != NULL)
        {
            printf(" %d ", n->data);
            n = n->next;
        }
        printf("\n");
    }
}


int TakeElement(Pqueue* peil)       //fuckcija kuri isima pirmaji piroritetines eiles elementa
{
    int element;
    Node* t;

    if(peil->count == 0)
    {
        exit(2);
    }
    else
    {
        t = peil->head;
        element = t->data;
        peil->head = peil->head->next;
        peil->count--;
        free(t);
    }
    return element;
}



void DeletePQueue(Pqueue* peil)     //funkcija kuri istrina prioritetine eile
{
    Node* temp = NULL;

    while(peil->head != NULL)
    {
        temp = peil->head;
        peil->head = peil->head->next;
        free(temp);

        peil->count--;
    }


    free(peil->head);
}


int GetData(Pqueue* peil)       //funkcija kuri paima pirmo elemento data ne istraukiant jo is eiles
{
    if(peil->count == 0)
    {
        exit(2);
    }
    return peil->head->data;
}


