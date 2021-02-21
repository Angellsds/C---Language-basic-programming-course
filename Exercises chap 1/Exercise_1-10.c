#include <stdio.h>

int main(){
/*
    int c;
    
	while((c = getchar()) != EOF){
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        }
        if(c == ' '){
            putchar('\\');
            putchar('b');
        }
        if(c == '\\'){
            putchar('\\');
            putchar('\\');
        }
        if(c != '\t' && c != ' ' && c != '\\'){
            putchar(c);
        }
    }
}
*/
    char tab[3] = "\\t";
    char space[3] = "\\b";
    char backslash[4] = "\\\\";
	int c;
    
	while((c = getchar()) != EOF){
        if(c == '\t'){
            printf("%s", tab);
        }
        if(c == ' '){
            printf("%s", space);
        }
        if(c == '\\'){
            printf("%s", backslash);
        }
        if(c != '\t' && c != ' ' && c != '\\'){
            printf("%c",c);  
        }
    }
}

/*
    char a[3] = "\\n";

            printf("%s",a);
            */

