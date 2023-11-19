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

//FUNCIONES DE PILAS
void crearPila(Nodo **pila);
void push(Nodo** pila,int dato);
void cargarPila(Nodo **pila);
int pop(Nodo **pila);
bool isEmpty(Nodo *pila);

//FUNCIONES DE LISTAS
void crearLista(Nodo **lista);
void llenarLista(Nodo **pila, Nodo** lista);
void printList(Nodo *lista);
Nodo *insertarEnFrente(Nodo **lista,int dato);

//FUNCIONES GENERALES
bool determinarCapicua(int numero);

int main(){

    Nodo* lista;
    Nodo* pila;

    crearPila(&pila);
    crearLista(&lista);
    cargarPila(&pila);
    llenarLista(&pila,&lista);

    printList(lista);

    return 0;
}

//FUNCIONES DE PILA

void crearPila(Nodo **pila){

    printf("Pila creada \n");

    *pila=NULL;

    return;
}

int pop(Nodo** pila){

    int dato=(*pila)->dato;
    Nodo *aux=*pila;

    *pila=(*pila)->siguiente;
    free(aux);

    return dato;

}

void push(Nodo **pila, int dato){

    Nodo *nodoInsertar=(Nodo*)(malloc(sizeof(Nodo)));
    nodoInsertar->dato=dato;
    nodoInsertar->siguiente=NULL;
    nodoInsertar->siguiente=*pila;

    *pila=nodoInsertar;

    return;

}

void cargarPila(Nodo **pila){

    int dato=0;
    scanf("%d",&dato);
    while(dato!=0){
        printf("Elemento insertado: %d\n",dato);
        push(pila,dato);
        scanf("%d",&dato);
    }
    return;
}

bool isEmpty(Nodo *pila){
    return pila==NULL;
}

//FUNCIONES DE LISTA

void crearLista(Nodo** lista){

    printf("Lista creada \n");

    *lista=NULL;

    return;
}

Nodo *insertarEnFrente(Nodo **lista,int dato){

    Nodo *nodoInsertar=(Nodo*)(malloc(sizeof(Nodo)));
    nodoInsertar->dato=dato;
    nodoInsertar->siguiente=NULL;
    nodoInsertar->siguiente=*lista;

    *lista=nodoInsertar;

    printf("Insertado en lista exitosamente\n");

    return nodoInsertar;

}

void llenarLista(Nodo** pila, Nodo **lista){

    int valor;

    while(!isEmpty(*pila)){

        valor=pop(pila);

        //INSERTO EN LISTA
        if(determinarCapicua(valor)){
            insertarEnFrente(lista,valor);
        }
        //NO INSERTO EN LISTA
    }
    return;
}

void printList(Nodo* lista){
    printf("Numeros capicua\n");
    while(lista!=NULL){

        printf("Dato: %d \n",lista->dato);
        lista=lista->siguiente;
    }
    return;
}

//FUNCIONES GENERALES

bool determinarCapicua(int numero){

    bool boolean;
    int numeroSeparado[4]={0,0,0,0};
    int aux=0;

    //CORRESPONDE AL PRIEMR VALOR Y ASI AUMENTANDO
    numeroSeparado[0]=numero/10000;
    aux=numero%10000;

    numeroSeparado[1]=aux/1000;
    aux=aux%100;

    numeroSeparado[2]=aux/10;
    numeroSeparado[3]=aux%10;

    printf("%d \n",numeroSeparado[0]);
     printf("%d \n",numeroSeparado[1]);
      printf("%d \n",numeroSeparado[2]);
       printf("%d \n",numeroSeparado[3]);

    if((numeroSeparado[0]==numeroSeparado[2]) && (numeroSeparado[1]==numeroSeparado[3])){
        printf("entre\n");
        boolean=true;
    }else{
        printf("entre false\n");
        boolean=false;
    }

    return boolean;
}





