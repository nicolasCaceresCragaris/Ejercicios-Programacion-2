#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

using namespace std;

struct Nodo{

    int dato;
    Nodo *siguiente;

};

struct Queue{

    Nodo *frente;
    Nodo *fin;

};

void crearCola(Queue *cola);
void add(Queue *cola,int dato);
int remover(Queue *cola);
Queue apareo(Queue *colaA, Queue *colaB);
bool isEmpty(Queue cola);
void printQueue(Queue *cola);

int main(){

    Queue colaA;
    Queue colaB;
    crearCola(&colaA);
    crearCola(&colaB);

    add(&colaA,1);
    add(&colaA,5);
    add(&colaA,3);
    add(&colaA,2);
    add(&colaA,7);

    add(&colaB,2);
    add(&colaB,4);
    add(&colaB,3);




    Queue colaC=apareo(&colaA,&colaB);

    printQueue(&colaC);

    return 0;
}

void printQueue(Queue* cola){

    int dato=0;

    while(!isEmpty(*cola)){

        dato=remover(cola);

        printf("%d \n",dato);

    }
    return;
}

Queue apareo(Queue *colaA, Queue *colaB){

    Queue colaC;
    crearCola(&colaC);

    while(!isEmpty(*colaA)){

        add(&colaC,remover(colaA));
    }
    while(!isEmpty(*colaB)){
        add(&colaC,remover(colaB));
    }

    return colaC;
}

bool isEmpty(Queue cola){

    return cola.fin==NULL && cola.frente==NULL;
}

int remover(Queue*cola){

    Nodo *aux=cola->frente;
    int dato=aux->dato;
    cola->frente=aux->siguiente;

    if(cola->frente==NULL){
        cola->fin=NULL;
    }

    free(aux);
    return dato;

}


void add(Queue *cola,int dato){

    Nodo *nodoInsertar=(Nodo*)(malloc(sizeof(Nodo)));
    nodoInsertar->dato=dato;
    nodoInsertar->siguiente=NULL;

    if(cola->frente==NULL){
        cola->frente=nodoInsertar;
    }else{
        cola->fin->siguiente=nodoInsertar;
    }

    cola->fin=nodoInsertar;

    return;
}

void crearCola(Queue *cola){

    printf("Cola creada \n");
    cola->fin=NULL;
    cola->frente=NULL;

    return;
}
