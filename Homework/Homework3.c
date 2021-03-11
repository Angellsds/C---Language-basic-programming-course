#include <stdio.h>
#define First 1
#define Last 0


int main(){

    int c, state = Last;
    char a[6]={']','}',')','\"','\'','>'};
    int i = 0;
    int p = Last;
    int n = Last;
    while ((c = getchar()) != EOF){

        switch(c){
        case '[':
              state = First;
              i = 0;
            break;
        case '{':
              state = First;
              i = 1;
            break;
        case '(':
              state = First;
              i = 2;
            break;
        case '\"':
              state = First;
              i = 3;
            break;
        case '\'':
              state = First;
              i = 4;
            break;
        case '<':
              state = First;
              i = 5;
            break;
        }
        if(state == First){
           do {
        if(c =='.' || c ==',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '?' || c == '¿'){
            while((c = getchar()) == '.' || c ==',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '?' || c == '¿'){
                ;
            }
           }
           putchar(c);
          } while((c = getchar()) != a[i]);
            state = Last;
        }
        if(state == Last ){
           if(c >= '0' && c <= '9'){
                p == First ? :printf("X");
            while((c = getchar()) >= '0' && c <= '9'){
                ;
            }
            n = First;
        }
        if(c =='.' || c ==',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '?' || c == '¿'){
            while((c = getchar()) == '.' || c ==',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '?' || c == '¿'){
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
//Antes habian comentarios pero arregle algo y los borre por que me estorbaban mucho:((((
