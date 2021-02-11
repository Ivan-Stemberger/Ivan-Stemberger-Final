#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Envio.h"


/** \brief Carga los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEnvio)
{
    int load;

    FILE* pFile = fopen("MOCK_DATA_final.csv", "r");
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

/** \brief Listar envios
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEnvio(LinkedList* pArrayListEnvio)
{
    Eenvio* envio;
    int indice= ll_len(pArrayListEnvio);
    int i;
    char entrega[22];

    printf("\nId   |   Nombre    |   KM   |   Entrega\n");


    for (i=0;i<indice;i++)
    {
        envio = (Eenvio*)ll_get(pArrayListEnvio,i);

        if(envio->entrega == 1)
        {
            strcpy(entrega,"Normal");

        }
        else if(envio->entrega == 2)
        {
            strcpy(entrega,"Express");

        }
        else
        {
            strcpy(entrega,"Segun disponibilidad");

        }

        printf("%d   |   %s    |   %d    |   %s \n",envio->id,envio->nombre,envio->km,entrega);

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

