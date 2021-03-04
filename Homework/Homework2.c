
#include <stdio.h>
#define k 30    //cantidad de numeros primos a buscar    ~SOLO CAMBIAR ESTE VALOR PARA TAREA~
#define MAX 128 // para 8 bits

int main (){   //consigue los primeros k numeros primos

	int x, i,cont = 0;
	int state = 0;
    unsigned int binario = MAX;
    printf("Los primeros %d numeros primos son:\n\n", k);
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
