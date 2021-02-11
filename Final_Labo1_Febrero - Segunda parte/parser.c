#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Envio.h"
#include "Entrega.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEnvio)
{


    int cantidad = 0;
    char idStr[6];
    char nombreStr[20];
    char kmStr[8];
    char entregaStr[6];


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, kmStr, entregaStr);
            if(cantidad != 4)
            {
                printf("Error en la carga\n\n");
                system("pause");
            }
            else
            {
                Eenvio* envio = envio_new();
                envio->id = atoi(idStr);
                strcpy(envio->nombre, nombreStr);
                envio->km = atoi(kmStr);
                envio->entrega = atoi(entregaStr);

                ll_add(pArrayListEnvio, envio);
            }
        }
    fclose(pFile);
    return 1;
    }
    else
    {
        printf("No hay archivo.\n");
        system("pause");
        return 0;
    }

}


int parser_EntregaFromText(FILE* pFile , LinkedList* pArrayListEnvio)
{


    int cantidad = 0;
    char idStr[25];
    char descripcionStr[25];


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,\n]\n", idStr, descripcionStr);
            if(cantidad != 2)
            {
                printf("Error en la carga\n\n");
                system("pause");
            }
            else
            {
                etipoEntrega* entrega = entrega_new();
                entrega->id = atoi(idStr);
                strcpy(entrega->descripcion, descripcionStr);

                ll_add(pArrayListEnvio, entrega);
            }
        }
    fclose(pFile);
    return 1;
    }
    else
    {
        printf("No hay archivo.\n");
        system("pause");
        return 0;
    }

}

