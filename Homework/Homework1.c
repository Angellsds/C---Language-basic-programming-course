
#include <stdio.h>

int main(){
    int c, i = 0;
    char stro[13]={"strong/strong"};
    char scrip[3]={"scrip"};
	
        while((c = getchar()) != EOF)
    {
        if(c == '<')
        {
            while((c = getchar()) == stro[i]){
                i++;
            }
            if(c == scrip[1]){
                c = getchar();
                if(c == scrip[2]){
                    c = getchar();
                    if (c == scrip[3]){
                        while ((c = getchar()) != '>'){
                            ;
                        }
		    	while((c = getchar()) != '/'){
                            ;
                        }
                        while((c = getchar()) != '>'){
                            ;
                        }
                    }
                }
            }
            if(i == 13){
                i =0;
            }
             while(c != EOF && c != '>'){
                c = getchar();
            }
        }
        else if (i == 6 && i < 13){
                if(c == ' '){
                    printf("_");
                }
            putchar(c);
           }
            if ((i != 6 && c != '<' && c != '>') || c == '\n'){
            putchar(c);
            i = 0;
            }
    }
}
