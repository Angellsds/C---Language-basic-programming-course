#include <stdio.h>
#define First 1
#define Last 0


int main(){

    int c, state = Last;    //declare c que es para los caracteres y state que me dira en que estado estan las llaves o comillas, etc.
    int n = First;      //solo la agregue pare resolver algo que en caso de haber un signo de puntuacion, no mostraba el caracter sig debido a la estructura de un if que estableci
    int p = Last;       // la use para identificar si despues del punto seguia un numero, si era asi, no agregaria otra x ejemp: Correcto 123.12.12 ---> X / Mal 123.12.12 ---> XXX

    while ((c = getchar()) != EOF){     //ciclo para pedir caracteres

        switch(c){                  // aqui imprimo todo lo que este entre un par de [] o {} o "" o <>
        case '[':                   // primer caso, nos encontramos con [
              state = First;        //declaramos el estado como first, haciendo mencion a que se inicio un corchete
              putchar(c);           //muestro el corchete
              do {putchar(c);} while((c = getchar()) != ']');        //ciclo para pedir caracteres y mostrarlos siempre y cuando no sea ]
              state = Last;                         //declaro el estado como last, haciendo mencion a que se encontro el cierre ]
            break;
        case '{':                           //aca se hace lo mismo si el caracter leido es {
              state = First;
              putchar(c);
              do {putchar(c);} while((c = getchar()) != '}');            //se repite lo mismo, solo que evaluando } en vez de ]
              state = Last;                     //declaro el estado como last
            break;
        case '(':
              state = First;
              putchar(c);
              do {putchar(c);} while((c = getchar()) != ')');        // lo mismo para los demas casos
              state = Last;
            break;
        case '"':
              state = First;
              putchar(c);
              do {putchar(c);} while((c = getchar()) != '"');
              state = Last;
        case '\'':
              state = First;
              putchar(c);
              do {putchar(c);} while((c = getchar()) != '\'');
              state = Last;
            break;
        case '<':
              state = First;
              putchar(c);
              do {putchar(c);} while((c = getchar()) != '>');
              state = Last;
            break;
        }
        if(state == Last ){     //se hace siempre y cuando el estado sea last
           if(c >= '0' && c <= '9' && p != First){    // si c es un numero
            printf("X");                //imprimimos x
            do {} while((c = getchar()) >= '0' && c <= '9'); //ciclo en el que pedimos un caracter y evaluamos si es un numero
            p = First;
        }
        if(c =='.' || c ==',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '?' || c == '¿'){ //si es un signo de puntuacion
            do {} while((c = getchar()) =='.' || c ==',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '?' || c == '¿'); //ciclo en el que pedimos un caracter y evaluamos si es puntuacion
            n = Last;
        }
        else if (p != First){
            putchar(c);//si no es un signo de puntuacion, lo mostramos
        }
        if(n == Last && c!= '0' && c!= '1' && c!= '2' && c!= '3' && c!= '4' && c!= '5' && c!= '6' && c!= '7' && c!= '8' && c!= '9'){   //si n es last y no es ningun numero
            putchar(c);         //mostramos el caracter
            n = First;          // establecemos n como inicio
            p = Last;
        }
      }

   }
}

//Creado por mi cuenta, lo hubiera hecho sin switch, pero me parecio una buena idea implementar ese nuevo statement al igual que el do while
