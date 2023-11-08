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

void insertar(Nodo**pila, int valor, int posicion){

     Nodo *pilaAux;
     create(&pilaAux);

     for(int i=1;i<posicion;i++){
        push(&pilaAux,pop(pila));

        if(isEmpty(*pila)){
            printf("La pila es mas chica que la posicion ingresada \n");
            return;
        }
     }
     push(pila,valor);

     while(!isEmpty(pilaAux)){
        push(pila,pop(&pilaAux));
     }

    return;
}


int main()
{
    Nodo *pila;
    int valor=0;
    int posicion=0;

    create(&pila);


    printf("Ingrese el valor a insertar \n");
    scanf("%d",&valor);
    printf("Ingrese la posicion donde quiere insertarlo \n");
    scanf("%d",&posicion);


    cargarPila(&pila);

    insertar(&pila,valor,posicion);

    vaciar(&pila);


    return 0;
}
