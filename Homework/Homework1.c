
#include <stdio.h>

int main(){
    int c, i = 0 ;
	char stro[13]={"strong/strong"};
    char scrip[13]={"script/script"};
        while((c = getchar()) != EOF)
    {
        if(c == '<')
        {
            while((c = getchar()) == stro[i]){		//check if the word between <> is strong
                i++;
            }
            if(c == scrip[1]){ //c			//this chain of if check if the word between is script in case the word isn't strong
                c = getchar();
                if(c == scrip[2]){  //r
                    c = getchar();
                    if (c == scrip[3]){ //i
                        c = getchar();
                        if(c == scrip[4]){  //p
                            c = getchar();
                            if(c == scrip[5]){  //t
                        while ((c = getchar()) != '>'){		//getchar with while to find the end of the character 
                            ;
                        }
                        while((c = getchar()) != '/'){		//to get this character to ensure that we reach the end of the tag
                            ;
                        }
                        while((c = getchar()) != '>'){		//to ensure that we are in the end of tne tag
                            ;
                            }
                        }
                     }
                  }
               }
            }
            if(i == 13){	// if i =  13 i is going to reset its value, bc i is the number that tells to my program when the tag strong finish
                i =0;		// restart the i value
            }
             while(c != EOF && c != '>'){	// to get all character between <>
                c = getchar();
            }
        }
        else if (i == 6 && i < 13 && c != '<'){		// if c != '/' this else if happen, and replace each blank with undersocre
                if(c == ' '){
                    printf("_");

                }
                putchar(c);
           }
            if ((i != 6 && c != '<' && c != '>') || c == '\n'){	  //to put words between tags <> ** <>
            putchar(c);
            i = 0;		//restart the count of i bc i wasn't equal to 6 and that means the tag wasn't strong
            }
    }
}

