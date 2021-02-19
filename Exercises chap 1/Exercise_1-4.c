#include <stdio.h>
#define low 0
#define top 300
#define step 20

int main()
{

    int f, c;
    float way;

    printf("Type 1 to convert Faharenheit to Celsius and 0 for the opposite: ");
    scanf("%f", &way);
    if (way !=0.0 && way!=1.0){
        printf(" -----------------------\n |Choose a valid option|\n -----------------------\n ");
        return 0;
    }
        if (way == 1){
                    f = low;
            printf("\n  F\t\tC\n------------------- \n");
                while (f <= top){
                    c = 5 * (f - 32) / 9;
                    printf("%3d F\t =%7d C\n", f, c);
                    f = f + step;
    }
    }
        else{
                    c = low;
            printf("  C\t\tF\n------------------- \n");
                while (c <= top){
                    f = 9 * c / 5  + 32;
                    printf("%3d C\t =%7d F\n", c, f);
                    c = c + step;
        }
    }
}
