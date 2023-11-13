#include <iostream>

using namespace std;


struct Nodo{

    char dato;
    Nodo *sgt;
};

void create(Nodo **head){

    *head=NULL;
    printf("Pila creada \n");
    return;
}

bool isEmpty(Nodo *pila){
    return pila==NULL;
}


void push(Nodo **head,int dato){
    Nodo *newNodo=(Nodo*)(malloc(sizeof(Nodo)));
    newNodo->dato=dato;
    newNodo->sgt=NULL;


     newNodo->sgt=*head;
     *head=newNodo;

    printf("Valor ingresado en pila \n");
     return;
}

char pop(Nodo **pila){

    char valor=(*pila)->dato;
    Nodo*aux=*pila;
    *pila=(*pila)->sgt;
    free(aux);

    printf("Nodo liberado \n");
    return valor;
}

void vaciar(Nodo **pila){

    while(!isEmpty(*pila)){

        printf("%d \n",pop(pila));
    }
    return;
}

void cargarPila(Nodo**pila){

    char dato=0;


    printf("Ingrese el char \n");
    scanf(" %c",&dato);

    while(dato!='0'){

        push(pila,dato);
        printf("Ingrese el char \n");
        scanf(" %c",&dato);
    }
    return;
}

bool inversa(Nodo **pila){

    Nodo *pilaAux;
    create(&pilaAux);

    char caracter = pop(pila);

    while(caracter!='.'){
        push(&pilaAux,caracter);
        caracter=pop(pila);
    }

    while(!isEmpty(*pila)&& !isEmpty(pilaAux)){

            if(pop(pila)!= pop(&pilaAux)){

                return false;
            }

    }

    return true;
}


int main()
{
    Nodo *pila;

    create(&pila);

    cargarPila(&pila);

    if(inversa(&pila)){
        printf("Es inversa \n");
    }
    else{
        printf("No es inversa \n");
    }


    return 0;
}
