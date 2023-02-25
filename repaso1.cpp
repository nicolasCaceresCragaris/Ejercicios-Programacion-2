#include <iostream>

using namespace std;

void cargarVector(int vec[]){

    int i=0;

    while(i<10){

        if(i==0){
            vec[i]=i+1;
        }else{
            vec[i]=(i)*(i+1);

        }

        i++;
    }


    return;
}

void mostrarVector(int vec[]){

    printf("================================================= \n");

    for(int i=0; i<10;i++){
        printf("Posicion: %d Contenido: %d \n",i+1,vec[i]);

    }

    return;
}

void invertirVector(int vec[]){

    int i=0;
    int j=9;
    int aux=0;

    while(i<5){

        aux=vec[i];
        vec[i]=vec[j];
        vec[j]=aux;

        i++;
        j--;
    }


    return;
}

int main()
{
    int vec[10];

    cargarVector(vec);
    mostrarVector(vec);
    invertirVector(vec);
    mostrarVector(vec);

    return 0;
}
