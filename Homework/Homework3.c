#include <stdio.h>
#define First 1
#define Last 0


int main(){

    int c, state = Last;    //declare c que es para los caracteres y state que me dira en que estado estan las llaves o comillas, etc.
    int p = Last;       // la use para identificar si despues del punto seguia un numero, si era asi, no agregaria otra x ejemp: Correcto 123.12.12 ---> X / Mal 123.12.12 ---> XXX
    int n = Last;
    while ((c = getchar()) != EOF){     //ciclo para pedir caracteres

        switch(c){                  // aqui imprimo todo lo que este entre un par de [] o {} o "" o <>
        case '[':                   // primer caso, nos encontramos con [
              state = First;        //declaramos el estado como first, haciendo mencion a que se inicio un corchete
              do {putchar(c);} while((c = getchar()) != ']');        //ciclo para pedir caracteres y mostrarlos siempre y cuando no sea ]
              state = Last;                         //declaro el estado como last, haciendo mencion a que se encontro el cierre ]
            break;
        case '{':                           //aca se hace lo mismo si el caracter leido es {
              state = First;
              do {putchar(c);} while((c = getchar()) != '}');            //se repite lo mismo, solo que evaluando } en vez de ]
              state = Last;                     //declaro el estado como last
            break;
        case '(':
              state = First;
              do {putchar(c);} while((c = getchar()) != ')');        // lo mismo para los demas casos
              state = Last;
            break;
        case '\"':
              state = First;
              do {putchar(c);} while((c = getchar()) != '\"');
              state = Last;
            break;
        case '\'':
              state = First;
              do {putchar(c);} while((c = getchar()) != '\'');
              state = Last;
            break;
        case '<':
              state = First;
              do {putchar(c);} while((c = getchar()) != '>');
              state = Last;
            break;
        }
        if(state == Last ){     //se hace siempre y cuando el estado sea last
           if(c >= '0' && c <= '9'){    // si c es un numero
                p == First ? :printf("X");                //imprimimos x si p no es First
            while((c = getchar()) >= '0' && c <= '9'){ //ciclo en el que pedimos un caracter y evaluamos si es un numero
                ;
            }
            n = First;
        }
        if(c =='.' || c ==',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '?' || c == '¿'){ //si es un signo de puntuacion
            while((c = getchar()) == '.' || c ==',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '?' || c == '¿'){ //ciclo en el que pedimos un caracter y evaluamos si es puntuacion
                ;
            }
            n == First ? p = First : "";
        }
         if(c!= '0' && c!= '1' && c!= '2' && c!= '3' && c!= '4' && c!= '5' && c!= '6' && c!= '7' && c!= '8' && c!= '9') {
            putchar(c);
            p = Last;
            n = Last;
        }
      }

   }
}
