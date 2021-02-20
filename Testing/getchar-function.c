#include <stdio.h>


int main(){

    int c;
/*
    c = getchar();
    while (c != EOF) {
        putchar(c);
        getchar();
    }

}
*/


    c = getchar();
    printf("%c", c);
    c = getchar();
    printf("%c", c);
    c = getchar();
    printf("%c", c);
    c = getchar();
    putchar(c);
    c = getchar();
    putchar(c);

/*
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
return 0;
*/
}


