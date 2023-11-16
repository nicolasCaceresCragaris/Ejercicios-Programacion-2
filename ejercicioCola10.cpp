#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

struct Queue{

    Nodo *inicio;
    Nodo *fin;

};

void crear(Queue *cola){

    printf("Cola inicializada \n");
    cola->inicio=NULL;
    cola->fin=NULL;

};

void add(Queue *cola,int dato){

    Nodo *nuevoNodo=(Nodo*)(malloc(sizeof(Nodo)));

    nuevoNodo->dato=dato;
    nuevoNodo->siguiente=NULL;

    if(cola->inicio==NULL){
        cola->inicio=nuevoNodo;
    }else{
        cola->fin->siguiente=nuevoNodo;
    }

    cola->fin=nuevoNodo;

    return;
}

int remover(Queue *cola){

    Nodo *nodoAuxiliar=cola->inicio;
    int dato=nodoAuxiliar->dato;
    cola->inicio=nodoAuxiliar->siguiente;

    if(cola->inicio==NULL){
        cola->fin=NULL;
    }
    free(nodoAuxiliar);
    return dato;
}

bool isEmpty(Queue *cola){

    return cola->inicio==NULL && cola->fin==NULL;
}

void eliminarDosNodos(Queue *cola,char &eliminado){

    int contador=0;
    for(int i=0;i<2;i++){
        if(!isEmpty(cola)){
            remover(cola);
            contador++;
        }
    }

    if(contador==2){
        eliminado='S';
    }else{
        eliminado='N';
    }
    return;
}

void vaciarCola(Queue *cola){

    while(!isEmpty(cola)){
        printf("%d \n",remover(cola));
    }

}

int main(){

    Queue cola;
    char eliminado;
    int dato=0;
    crear(&cola);

    printf("Ingrese dato \n");
    scanf("%d",&dato);

    while(dato!=0){

        add(&cola,dato);

        printf("Ingrese dato \n");
        scanf("%d",&dato);
    }

    eliminarDosNodos(&cola,eliminado);

    if(eliminado=='S'){
        printf("Se pudo eliminar 2 nodos\n");
    }
    if(eliminado=='N'){
        printf("No se pudo eliminar 2 nodo \n");
    }

    vaciarCola(&cola);

    return 0;

}
