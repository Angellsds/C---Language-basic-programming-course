#include <stdio.h>


int main()
{
    int f, c;
    int low, top, step;

    low = 0;   /* lower limit of temperature table*/
    top = 300;    /* upper limit*/
    step = 20;   /* step size*/

    f = low;
    while (f <= top){
        c = 5 * (f - 32) / 9;
        printf("%d F\t=\t%d C\n", f, c);
        f = f + step;
    }

}
