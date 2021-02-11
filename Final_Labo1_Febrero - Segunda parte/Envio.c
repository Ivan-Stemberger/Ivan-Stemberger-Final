#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Envio.h"


Eenvio* envio_new(void)
{
    Eenvio* envio = (Eenvio*)malloc(sizeof(Eenvio));

    if(envio == NULL)
    {
        printf("No hay espacio para un nuevo empleado.\n");
        return 0;
    }
    else
    {
        envio->id = 0;
        strcpy(envio->nombre, "");
        envio->km = 0;
        envio->entrega = 0;
        envio->precio = 0;
    }
    return envio;

}

void precioEnvio(Eenvio* envio)
{


        if(envio->km < 45)
        {
            if(envio->entrega == 1)
            {
                envio->precio = 350 + 77*envio->km;
            }
            else if(envio->entrega == 2)
            {
                envio->precio = 580 + 77*envio->km;
            }
            else
            {
                envio->precio = 90 + 77*envio->km;
            }

        }
        else
        {
            if(envio->entrega == 1)
            {
                envio->precio = 350 + 90*envio->km;
            }
            else if(envio->entrega == 2)
            {
                envio->precio = 580 + 90*envio->km;
            }
            else
            {
                envio->precio = 90 + 90*envio->km;
            }
        }


}





