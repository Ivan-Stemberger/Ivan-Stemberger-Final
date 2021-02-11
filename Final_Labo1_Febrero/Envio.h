#ifndef envio_H_INCLUDED
#define envio_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int km;
    int entrega;
    int precio;
}Eenvio;


Eenvio* envio_new();
void precioEnvio(Eenvio* envio);


#endif // envio_H_INCLUDED
