
#include <stdio.h>
#define k  10   //cantidad de numeros primos a buscar    ~SOLO CAMBIAR ESTE VALOR PARA TAREA~
#define MAX 128 // para 8 bits = 128   16 bits = 32768    32 bits = 2147483648  ~EN CASO DE ASIGNAR UN VALOR K QUE DE UN VALOR QUE NO PUEDE SER REPRESENTADO POR 8 BITS~
int prime(/**/);
int contador (/**/);

long main (){   //consigue los primeros k numeros primos

	long x, i,cont = 0;
	long state = 0;
    unsigned long binario = MAX;
    printf(k <= 1 ? "El primer numero primo es:\n\n" :"Los primeros %d numeros primos son:\n\n", k);
	for(i = 2 ; cont < k ;i++){
        state = 0;
		for(x = 2 ; x <= i ;x++){
		if(i % x == 0){
            state++;
		}

	}
        if(state == 1){
		printf("%3d = ",i);
        cont++;
		state = 0 ;

      for(binario = MAX; binario > 0; binario >>= 1){
        if (binario & i){
            printf("1");
        }
        else{
            printf("0");
        }
      }
      printf("\n");
    }

  }
}
