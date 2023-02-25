#include <iostream>

using namespace std;

int main()
{

    int n=0;
    int valorMasAlto=0;
    int valorMasBajo=0;
    int contador=0;
    int acumulador=0;
    float promedio=0;

    printf("Ingrese valores distintos a 0 \n");
    scanf("%d",&n);

    while(n!=0){
        contador++;

        if(contador==1){
            valorMasAlto=n;
            valorMasBajo=n;

        }
        if(contador!=1 && n>valorMasAlto){
            valorMasAlto=n;
        }
        if(contador!=1 && n<valorMasBajo){
            valorMasBajo=n;
        }

        printf("Ingrese valores distintos a 0 \n");
        scanf("%d",&n);

        acumulador=acumulador+n;
    }

    promedio=acumulador/contador;

    printf("El valor mas alto fue %d \n",valorMasAlto);
    printf("El valor mas bajo fue %d \n",valorMasBajo);
    printf("El promedio fue: %f \n",promedio);
    printf("Se ingresaron un total de %d numeros. \n",contador);


    return 0;
}
