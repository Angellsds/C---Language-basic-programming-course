
typedef struct TDAArbol
{
    struct TDAArbol *izq;
    struct TDAArbol *der;
    char *cadena;
} *Arbol;

Arbol arbol_insertar (Arbol nodo, const char *cadena);
Arbol arbol_quitar (Arbol nodo, const char *cadena);
void arbol_inorden (Arbol nodo);

