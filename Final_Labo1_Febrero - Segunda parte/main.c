#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Envio.h"
#include "Controller.h"

int main()
{
    int opcion = 0;
    int binario=0;
    int texto=0;
    LinkedList* listaEnvios = ll_newLinkedList();
    LinkedList* listaEntregas = ll_newLinkedList();


    do{
        printf("Por favor, seleccione una de las siguientes opciones para continuar:\n\n"
        "1) Cargar archivo\n"
        "2) Imprimir Envios\n"
        "3) Generar archivo de costos.\n"
        "4) Salir\n"
        );

        scanf("%d",&opcion);



        switch(opcion)
        {
            case 1:
            {
                if(!texto && controller_loadEnvioFromText("MOCK_DATA_final.csv",listaEnvios) && controller_loadEntregaFromText("tipo_de_entregas.txt",listaEntregas))
                {
                    texto = 1;
                }
                else
                {
                    printf("/nArchivo abierto./n");
                }
                break;
            }

            case 2:
            {
                if(binario || texto)
                {
                    controller_ListEnvio(listaEnvios,listaEntregas);
                }
                else
                {
                    printf("Primero abra el archivo.");
                }

                break;
            }

            case 3:
            {
                if(binario || texto)
                {
               controller_saveAsText("data.csv" , listaEnvios);
                }
                else
                {
                    printf("Primero abra el archivo.");
                }

                break;
            }

        }
    }while(opcion != 4);


    return 0;
}
