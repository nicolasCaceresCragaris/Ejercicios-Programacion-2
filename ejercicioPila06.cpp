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

void cargarPila(Nodo**pila){

    int dato=0;


    printf("Ingrese el valor \n");
    scanf("%d",&dato);

    while(dato!=0){

        push(pila,dato);
        printf("Ingrese el valor \n");
        scanf("%d",&dato);
    }
    return;
}

void hacerRemplazo(Nodo**pila, int valorQuitar, int valorInsertar){

    Nodo *pilaAux;
    int valor=0;

    create(&pilaAux);

    while(!isEmpty(*pila)){

        valor=pop(pila);

        if(valor==valorQuitar){
            push(&pilaAux,valorInsertar);
        }
        else{
            push(&pilaAux,valor);
        }
    }

    while(!isEmpty(pilaAux)){
        push(pila,(pop(&pilaAux)));
    }


    return;
}


int main()
{
    Nodo *pila;
    int valorQuitar=0;
    int valorInsertar=0;


    create(&pila);


    printf("Ingrese el valor a quitar \n");
    scanf("%d",&valorQuitar);

    printf("Ingrese el valor a insertar \n");
    scanf("%d",&valorInsertar);


    cargarPila(&pila);

    hacerRemplazo(&pila,valorQuitar,valorInsertar);

    vaciar(&pila);


    return 0;
}
