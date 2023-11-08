#include <iostream>

using namespace std;


struct Nodo{

    int dato;
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

int pop(Nodo **pila){

    int valor=(*pila)->dato;
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

void cargarPila(Nodo**pila,int valor){

    int dato=0;
    int contador=1;

    printf("Ingrese el valor \n");
    scanf("%d",&dato);

    while(dato!=0){

        if(contador!=3){
            push(pila,dato);
            printf("Ingrese el valor \n");
            scanf("%d",&dato);
            contador++;
        }
        if(contador==3){
            push(pila,valor);
            contador++;
        }
    }
    return;
}



int main()
{
    Nodo *pila;
    int valor;

    create(&pila);


    printf("Ingrese el valor a colocar adelante\n");
    scanf("%d",&valor);

    cargarPila(&pila,valor);

    vaciar(&pila);


    return 0;
}
