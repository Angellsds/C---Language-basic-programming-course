#include <stdio.h>

int main(){

    int state, c;
    state = 0;

     while((c = getchar()) != EOF){
         
         if (state == 0){
             printf("\n");
             state = 1;
         }
         putchar(c);

         if ( c == ' ' || c == '\n' || c == '\t'){
             while ((c = getchar()) == ' ' || c == '\n' || c == '\t')
             {
                 ;
             }
             printf("\n%c",c);
         }

     }

}