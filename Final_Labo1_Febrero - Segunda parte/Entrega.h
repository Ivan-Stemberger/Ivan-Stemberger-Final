#ifndef entrega_H_INCLUDED
#define entrega_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[128];

}etipoEntrega;


etipoEntrega* entrega_new(void);
//*void precioEnvio(Eenvio* envio);


#endif // entrega_H_INCLUDED
