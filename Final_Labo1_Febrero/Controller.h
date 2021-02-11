int controller_loadFromText(char* path , LinkedList* pArrayListEnvio);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEnvio);
int controller_addEnvio(LinkedList* pArrayListEnvio);
int controller_editEnvio(LinkedList* pArrayListEnvio);
int controller_removeEnvio(LinkedList* pArrayListEnvio);
int controller_ListEnvio(LinkedList* pArrayListEnvio);
int controller_sortEnvio(LinkedList* pArrayListEnvio);
int controller_saveAsText(char* path , LinkedList* pArrayListEnvio);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEnvio);
