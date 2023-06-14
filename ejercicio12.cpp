#include <iostream>
#include <string.h>
#include <stdlib.h>

struct Producto{

    char codigoProducto[4];
    int stock;
};

struct Pedido{
    int numeroDePedido;
    char codigoProducto[4];
    int numeroDeCliente;
    int cantidadPedida;

};


//FUNCION PARA CREAR UN ARCHIVO DE PRODUCTOS
void crearArchivo(Producto vecProductos[],int n){

    FILE *archivoNuevo=fopen("stockProductos","wb");

    for(int i=0;i<n;i++){
        fwrite(&vecProductos[i],sizeof(Producto),1,archivoNuevo);
    }

    printf("Se creo el archivo exitosamente \n");


    fclose(archivoNuevo);

    return;
};

//FUNCION PARA CREAR UN ARCHIVO DE PEDIDOS

void crearArchivoPedidos(Pedido vecPedidos[], int n){
    FILE *archivoNuevo=fopen("pedidos","wb");

    for(int i=0;i<n;i++){
        fwrite(&vecPedidos[i],sizeof(Pedido),1,archivoNuevo);

    }
    printf("Se creo el archivo exitosamente \n");
    fclose(archivoNuevo);
    return;
}

using namespace std;



    int main(){

        Producto vectorProductos[20]{
            {"1",150},
            {"2",150},
            {"3",150},
            {"4",150},
            {"5",150},
            {"6",150},
            {"7",150},
            {"8",150},
            {"9",150},
            {"10",150},
            {"11",150},
            {"12",150},
            {"13",150},
            {"14",150},
            {"15",150},
            {"16",150},
            {"17",150},
            {"18",150},
            {"19",150},
            {"20",150}
        };

        Pedido vectorPedidos[30]{
            {1,"1",1000,40},
            {2,"1",1002,50},
            {3,"11",1003,140},
            {4,"2",1004,150},
            {5,"20",1005,20},
            {6,"2",1006,10},
            {7,"3",1007,100},
            {8,"13",1008,30},
            {9,"3",1009,40},
            {10,"4",1010,150},
            {11,"14",1011,15},
            {12,"4",1012,150},
            {13,"5",1013,15},
            {14,"15",1014,150},
            {15,"5",1015,15},
            {16,"6",1016,10},
            {17,"16",1017,50},
            {18,"6",1018,50},
            {19,"7",1019,50},
            {20,"17",1020,150},
            {21,"7",1021,50},
            {22,"8",1022,45},
            {23,"18",1023,30},
            {24,"8",1024,11},
            {25,"9",1025,10},
            {26,"19",1026,30},
            {27,"9",1027,150},
            {28,"11",1028,50},
            {29,"10",1029,50},
            {30,"10",1030,50}
        };
        //==================================================================
        //==================================================================
        int afirmacion=0;

        printf("Reescribir de nuevo los archivos 1 si 0 no \n");
        scanf("%d",&afirmacion);
        if(afirmacion==1){
            crearArchivo(vectorProductos,20);
            crearArchivoPedidos(vectorPedidos,30);
        }

        //=================================================================

        Pedido pedidoLeido;
        Producto productoLeido;

        int pos=0;

        FILE*archivoPedidos=fopen("pedidos","rb");
        FILE*archivoProductos=fopen("stockProductos","rb+");
        FILE*archivoSatisfechos=fopen("pedidosCompletos","wt");
        FILE*archivoIncompletos=fopen("pedidosincompletos","wt");

        fprintf(archivoSatisfechos,"NroPedido \t NroCliente \t CodigoProducto \t CantidadPedida \n");
        fprintf(archivoIncompletos,"NroPedido \t NroCliente \t CodigoProducto \t CantidadPedida \n");


        fread(&pedidoLeido,sizeof(Pedido),1,archivoPedidos);

        printf("Usted leyo el pedido numero %d del cliente %d \n",pedidoLeido.numeroDePedido,pedidoLeido.numeroDeCliente);

        while(!feof(archivoPedidos)){

            fread(&productoLeido,sizeof(Producto),1,archivoProductos);

            while(!feof(archivoProductos)){

                if(strcmp(pedidoLeido.codigoProducto,productoLeido.codigoProducto)==0){
                    if((pedidoLeido.cantidadPedida<=productoLeido.stock)&& (productoLeido.stock>0)){
                        //PEDIDO SATISFECHO ENTONCES ESCRIBO EL ARCHIVO DE TEXTO DE PEDIDOS SATISFECHOS
                        printf("El pedido puede ser satisfecho \n");
                        fprintf(archivoSatisfechos,"%d \t %d \t %s \t %d \n",pedidoLeido.numeroDePedido,pedidoLeido.numeroDeCliente,pedidoLeido.codigoProducto,pedidoLeido.cantidadPedida);
                        //ACTUALIZAMOS EL STOCK

                        productoLeido.stock=productoLeido.stock-pedidoLeido.cantidadPedida;

                        pos=atoi(productoLeido.codigoProducto)-1;



                        //UTILIZANDO EL ID DE PRODUCTO POSICIONO EN EL ARCHIVO Y SOBREESCRIBO SIN DANIAR OTROS REGISTROS
                        fseek(archivoProductos,pos*sizeof(Producto),SEEK_SET);


                        fwrite(&productoLeido,sizeof(Producto),1,archivoProductos);

                        fseek(archivoProductos,0,SEEK_END);


                    }

                    else{
                        printf("El pedido no puede ser satisfecho \n");
                        fprintf(archivoIncompletos,"%d %d %s %d \n",pedidoLeido.numeroDePedido,pedidoLeido.numeroDeCliente,pedidoLeido.codigoProducto,pedidoLeido.cantidadPedida);
                        fseek(archivoProductos,0,SEEK_END);
                    }


                }

                fread(&productoLeido,sizeof(Producto),1,archivoProductos);

            }

            fseek(archivoProductos,0,SEEK_SET);


            fread(&pedidoLeido,sizeof(Pedido),1,archivoPedidos);

            printf("Usted leyo el pedido numero %d del cliente %d \n",pedidoLeido.numeroDePedido,pedidoLeido.numeroDeCliente);
        }




        printf("Fin del programa \n");
        return 0;
    }
