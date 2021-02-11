int controller_loadEnvioFromText(char* path , LinkedList* pArrayListEnvio);
int controller_loadEntregaFromText(char* path , LinkedList* pArrayListEnvio);
int controller_addEnvio(LinkedList* pArrayListEnvio);
int controller_editEnvio(LinkedList* pArrayListEnvio);
int controller_removeEnvio(LinkedList* pArrayListEnvio);
int controller_ListEnvio(LinkedList* pArrayListEnvio, LinkedList* pArrayListEntrega);
int controller_sortEnvio(LinkedList* pArrayListEnvio);
int controller_saveAsText(char* path , LinkedList* pArrayListEnvio);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEnvio);
