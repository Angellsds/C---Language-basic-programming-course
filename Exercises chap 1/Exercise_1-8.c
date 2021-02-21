#include<stdio.h>

/* count characters in input; 1st version */
void main(){

        int c, e1, t1, b1 ;

        e1 = 0;
        t1 = 0;
        b1 = 0;
        while ((c = getchar()) != EOF){
            if(c == '\n'){
            ++ e1;
            }
            if(c == '\t'){
            ++ t1;
            }
            if(c == ' '){
            ++ b1;
            }
        }
        printf("Blanks: %d\nTabs: %d\nNew Lines: %d", b1, t1, e1);
}