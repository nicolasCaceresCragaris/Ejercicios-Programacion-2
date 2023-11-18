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

void crearPila(Nodo**pila);
void push(Nodo** pila, int dato);
void cargarPila(Nodo **pila);
void ordenarPila(Nodo **pila);
void vaciarPila(Nodo **pila);
int pop(Nodo **pila);
bool isEmpty(Nodo *pila);


int main(){

    Nodo *pilaPrincipal;
    crearPila(&pilaPrincipal);
    cargarPila(&pilaPrincipal);
    ordenarPila(&pilaPrincipal);
    vaciarPila(&pilaPrincipal);

    return 0;
}

void crearPila(Nodo **pila){
    *pila=NULL;
    return;
}


bool isEmpty(Nodo *pila){
    return pila==NULL;
}

void push(Nodo** pila, int dato){


    Nodo* nodoInsertar=(Nodo*)(malloc(sizeof(Nodo)));
    nodoInsertar->dato=dato;
    nodoInsertar->siguiente=NULL;
    nodoInsertar->siguiente=*pila;

    *pila=nodoInsertar;



    return;
}

void cargarPila(Nodo** pila){

    int valor=0;

    printf("Ingrese un valor \n");
    scanf("%d",&valor);

    while(valor!=0){

        push(pila,valor);

        printf("Ingrese un valor \n");
        scanf("%d",&valor);

    }

    return;
}

int pop(Nodo **pila){

    int dato=(*pila)->dato;
    Nodo *aux=*pila;
    *pila=(*pila)->siguiente;
    free(aux);


    return dato;
}

void ordenarPila(Nodo** pila){

    int valor=0;
    int contador=0;
    int contadorNodos=0;
    int maximo=0;
    Nodo* pilaAux;
    Nodo* pilaSobrante;
    crearPila(&pilaAux);
    crearPila(&pilaSobrante);

    while(!isEmpty(*pila)){
        contadorNodos++;
        push(&pilaAux,pop(pila));
    }


    //PONER UN FOR EXTERNO
    for(int i=0;i<contadorNodos;i++){
        while(!isEmpty(pilaAux)){
            if (contador==0){
                maximo=pop(&pilaAux);
                push(&pilaSobrante,maximo);
                contador++;
            }
            if(contador>0){

                valor=pop(&pilaAux);
                if(valor>=maximo){
                    push(&pilaSobrante,maximo);
                    maximo=valor;

                }
                else{
                    push(&pilaSobrante,valor);
                }

            }

        }

        contador=0;

        push(pila,maximo);

        while(!isEmpty(pilaSobrante)){

            valor=pop(&pilaSobrante);
            if(valor!=maximo){
                push(&pilaAux,valor);
            }

        }
    }
    //PONER UN FOR EXTERNO

    return;
}

void vaciarPila(Nodo **pila){
    printf("============================\n");
    while(!isEmpty(*pila)){
        printf("%d\n",pop(pila));
    }


    return;
}
