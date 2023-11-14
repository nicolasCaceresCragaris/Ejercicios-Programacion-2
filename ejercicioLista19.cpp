#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;

};

void crear(Nodo **lista){
    printf("Lista creada exitosamente\n");
    lista=NULL;
    return;
}

Nodo *insertInFront(Nodo **lista,int dato){

    Nodo *nodo=(Nodo*)(malloc(sizeof(Nodo)));
    nodo->dato=dato;
    nodo->siguiente=NULL;

    nodo->siguiente=*lista;
    *lista=nodo;
    printf("Insertado en el frente \n");
    return nodo;
}

int countNodos(Nodo*lista){
    int counter=0;
    while(lista!=NULL){
        counter++;
        lista=lista->siguiente;
    }
   return counter;
}


void printList(Nodo*lista){
    while(lista!=NULL){

            printf("Dato: %d \n",lista->dato);
            lista=lista->siguiente;
    }


    return;
}

int main()
{

    Nodo *lista;
    crear(&lista);

    int dato=0;

    printf("Ingrese un numero \n");
    scanf("%d",&dato);

    while(dato!=0){

        insertInFront(&lista,dato);

        printf("Ingrese un numero \n");
        scanf("%d",&dato);
    }

    printf("Nodos: %d \n",countNodos(lista));
    printList(lista);

    return 0;
}
