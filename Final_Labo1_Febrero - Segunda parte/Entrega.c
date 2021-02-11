#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entrega.h"


etipoEntrega* entrega_new(void)
{
    etipoEntrega* entrega = (etipoEntrega*)malloc(sizeof(etipoEntrega));

    if(entrega == NULL)
    {
        printf("No hay espacio para un nuevo empleado.\n");
        return 0;
    }
    else
    {
        entrega->id = 0;
        strcpy(entrega->descripcion, "");

    }
    return entrega;

}
