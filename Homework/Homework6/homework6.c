#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include "header.h"

int main(void)
{
    Arbol raiz = NULL;
    char cadena[255];
    int opcion;
    do {
       system ("cls");
        printf (
           "      MENU\n"
           "1.- Insertar cadena\n"
           "2.- Quitar cadena\n"
           "3.- Listado de usuarios\n"
           "4.- Salir\n\n"
           "Seleccione una opcion: ");
       do {
           opcion = getchar ();
       } while (opcion<'1' || opcion>'4');
       printf ("%c\n\n", opcion);
       if (raiz == NULL && opcion != '1' && opcion != '4')
          printf ("El Arbol esta vacio.\n");
      else switch (opcion)
      {
      case '1':
        printf("Ingresa el usuario: ");
        scanf("%s", cadena);
        (void) getchar();
        raiz = arbol_insertar (raiz, cadena);
        printf("\nUsuario agregado correctamente\n");
        break;
      case'2':
        printf("Ingresa el usuario a eliminar: ");
        scanf("%s", cadena);
        (void) getchar();
        raiz = arbol_quitar (raiz, cadena);
        printf("\nUsuario borrado correctamente\n");
        break;
        case '3': arbol_inorden (raiz); break;
      }
      if (opcion!='4')
      {
          putchar('\n');
          system("pause");
      }
    }while (opcion != '4');
    return EXIT_SUCCESS;
}
Arbol arbol_insertar (Arbol nodo, const char *cadena)
{
    if (nodo == NULL)
    {
          nodo = (Arbol) malloc (sizeof (struct TDAArbol));
          nodo->izq = NULL;
          nodo->der = NULL;
          nodo->cadena = strdup (cadena);
    }
    else if (strcmp (cadena, nodo->cadena) < 0)
        nodo->izq = arbol_insertar (nodo->izq, cadena);
    else
        nodo->der = arbol_insertar (nodo->der, cadena);
    return nodo;
}

Arbol arbol_quitar (Arbol nodo, const char *cadena)
{
    Arbol pivote;
    int comparacion;
    if (nodo != NULL)
    {
        comparacion = strcmp (cadena, nodo->cadena);
        if (comparacion==0)
        {
            if (nodo->izq == NULL)
               pivote = nodo->der;
            else if (nodo->der == NULL)
                 pivote = nodo->izq;
            else
            {
              for (pivote = nodo->izq; pivote->der != NULL; pivote = pivote->der);
              pivote->der = nodo->der;
              pivote = nodo->izq;
            }
            free(nodo->cadena);
            free(nodo);
            nodo = pivote;
        }
        else if(comparacion <0)
            nodo->izq = arbol_quitar (nodo->izq, cadena);
        else
            nodo->der = arbol_quitar (nodo->der, cadena);
    }
    return nodo;
}

void arbol_inorden (Arbol nodo)
{
    if (nodo != NULL)
    {
        arbol_inorden (nodo->izq);
        printf("%s ", nodo->cadena);
        arbol_inorden (nodo->der);
    }
}

