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

bool isEmpty(Queue cola);
void crearCola(Queue *cola);
void add(Queue *cola , int dato);
void cargarCola(Queue* cola);
int remover(Queue *cola);
int contarNodos(Queue *cola);

int main(){

    Queue cola;
    crearCola(&cola);
    cargarCola(&cola);

    int nodosTotales=contarNodos(&cola);

    printf("Nodos totales %d \n",nodosTotales);

    return 0;
}

void crearCola(Queue *cola){
    printf("Cola creada \n");
    cola->frente=NULL;
    cola->fin=NULL;

    return;
}

int remover(Queue *cola){

    int dato=cola->frente->dato;
    Nodo *aux=cola->frente;
    cola->frente=aux->siguiente;

    if(cola->frente==NULL){
        cola->fin==NULL;
    }
    free(aux);
    return dato;

};

bool isEmpty(Queue cola){

    return cola.fin==NULL && cola.frente==NULL;
}

void add(Queue *cola, int dato){

    Nodo *nodoInsertar=(Nodo*)(malloc(sizeof(Nodo)));
    nodoInsertar->dato=dato;
    nodoInsertar->siguiente=NULL;

    if(cola->frente==NULL){
        cola->frente=nodoInsertar;
    }else{
        cola->fin->siguiente=nodoInsertar;
    }
    cola->fin=nodoInsertar;

    printf("Valor insertado\n");
    return;
}

void cargarCola(Queue *cola){

    int dato=0;
    printf("Ingrese dato \n");
    scanf("%d",&dato);

    while(dato!=0){

        add(cola,dato);

        printf("Ingrese dato \n");
        scanf("%d",&dato);
    }

    return;
}

int contarNodos(Queue *cola){

    int contador=0;
    Queue colaAux;
    crearCola(&colaAux);

    while(!isEmpty(*cola)){
        contador++;

        add(&colaAux,remover(cola));

    }

    while(!isEmpty(colaAux)){

        add(cola,remover(&colaAux));
    }

    return contador;
}
