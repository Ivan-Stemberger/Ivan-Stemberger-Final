#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Envio.h"
#include "Entrega.h"



/** \brief Carga los datos de los envios desde el archivo de texto pasado como parametro.
 *
 * \param path char* es el archivo de texto
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadEnvioFromText(char* path , LinkedList* pArrayListEnvio)
{
    int load;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        load = parser_EnvioFromText(pFile, pArrayListEnvio);
    }
    else
    {
        printf("El archivo no existe\n\n");
        system("pause");
        load = 0;
    }


    return load;
}


int controller_loadEntregaFromText(char* path , LinkedList* pArrayListEnvio)
{
    int load;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        load = parser_EntregaFromText(pFile, pArrayListEnvio);
    }
    else
    {
        printf("El archivo no existe\n\n");
        system("pause");
        load = 0;
    }


    return load;
}


/** \brief Lista los envios indicando con palabras los tipos de envio.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEnvio(LinkedList* pArrayListEnvio, LinkedList* pArrayListEntrega)
{
    Eenvio* envio;
    etipoEntrega* entrega;

    int indice= ll_len(pArrayListEnvio);
    int i;
    int j;


    printf("\nId   |   Nombre    |   KM   |   Entrega\n");


    for (i=0;i<indice;i++)
    {
        envio = (Eenvio*)ll_get(pArrayListEnvio,i);
        printf("%d",envio->id);

        for(j=0;j<ll_len(pArrayListEntrega);j++)
        {
            entrega = ll_get(pArrayListEntrega,j);

            if(envio->entrega == entrega->id)
            {
                break;
            }
        }


        printf("%d   |   %s    |   %d    |   %s \n",envio->id,envio->nombre,envio->km,entrega->descripcion);

    }


    return 1;
}


/** \brief Guarda los datos de los envios en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEnvio)
{
    FILE* archivo = fopen(path, "w");
    int len = ll_len(pArrayListEnvio);
    printf("%d",len);


    if(pArrayListEnvio != NULL )
    {
        fprintf(archivo, "id,nombre,km,entrega,precio\n");
        for(int i=0; i<ll_len(pArrayListEnvio); i++)
        {

                ll_map(pArrayListEnvio, precioEnvio);
                Eenvio* this = (Eenvio*) ll_get(pArrayListEnvio, i);

                fprintf(archivo, "%d,%s,%d,%d,%d\n", this->id, this->nombre, this->km, this->entrega, this->precio);


        }
        fclose(archivo);
        return 1;
        printf("\nLos datos han sido almacenados.\n");
    }
    else
    {
        return 0;
    }


}

