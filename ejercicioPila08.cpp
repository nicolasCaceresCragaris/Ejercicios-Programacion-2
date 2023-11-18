#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

using namespace std;

struct Nombre{

    char nombre[20];
    char apellido[20];

};


struct Nodo{
    Nombre dato;
    Nodo *siguiente;
};

void crearPila(Nodo** pila);
void push(Nodo**pila,Nombre registro);
void cargaDeDatos(Nodo**pila);
Nombre pop(Nodo**pila);
bool isEmpty(Nodo *pila);
void mostrarPilaInvertida(Nodo**pila);

int main(){

    Nodo *pila;
    crearPila(&pila);
    cargaDeDatos(&pila);
    mostrarPilaInvertida(&pila);


    return 0;

}

void mostrarPilaInvertida(Nodo **pila){

    Nodo *pilaAux;
    crearPila(&pilaAux);
    while(!isEmpty(*pila)){
        push(&pilaAux,pop(pila));
    }

    printf("Nombre \t Apellido \n");

    while(!isEmpty(pilaAux)){
        Nombre registro=pop(&pilaAux);
        printf("%s \t %s \n",registro.nombre,registro.apellido);

    }

    return;

}

bool isEmpty(Nodo* pila){

    return pila ==NULL;

}

void cargaDeDatos(Nodo **pila){

    Nombre nombreCompleto;

    printf("Ingrese el nombre \n");
    scanf("%s",nombreCompleto.nombre);
    printf("Ingrese el apellido \n");
    scanf("%s",nombreCompleto.apellido);

    while(strcmp(nombreCompleto.nombre,"FIN")!=0){

        push(pila,nombreCompleto);

        printf("Ingrese el nombre \n");
        scanf("%s",nombreCompleto.nombre);
        printf("Ingrese el apellido \n");
        scanf("%s",nombreCompleto.apellido);
    }

    return;
}

void crearPila(Nodo** pila){

    *pila=NULL;

    return;
}

void push(Nodo** pila, Nombre registro){

    Nodo* nodoInsertar=(Nodo*)(malloc(sizeof(Nodo)));

    nodoInsertar->dato=registro;
    nodoInsertar->siguiente=NULL;

    nodoInsertar->siguiente=*pila;
    *pila=nodoInsertar;

    return;

}

Nombre pop(Nodo** pila){

    Nombre nombre= (*pila)->dato;
    Nodo *nodoAux= *pila;
    *pila=(*pila)->siguiente;
    free(nodoAux);

    return nombre;
}
