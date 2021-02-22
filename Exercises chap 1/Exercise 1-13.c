#include<stdio.h>
#define MAX 100000

int main() {

    int c , i = 0;
    int nword[MAX] = {0};

    while((c=getchar())!= EOF) {

        if(c!=' '&& c!='\n'&&c!='\t') {
            ++nword[i];
        }
            else if (c == ' ' || c == '\n' || c == '\t'){
             while ((c = getchar()) == ' ' || c == '\n' || c == '\t')
             {
                 ;
             }
                ++i;
                ++nword[i];
            }
        }
        for (i = 0; i < MAX && nword[i+1] > 0; ++i){
            for(; nword[i] >0 ; nword[i]--){
                printf("x");
            }
            printf("\n");
           // printf("El index %d del array nword tiene un valor de %d\n", i, nword[i]);
        }
    }
