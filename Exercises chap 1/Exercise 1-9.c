
#include <stdio.h>

int main(){

	int c;
	while((c = getchar()) != EOF){

        putchar(c); //to put the character of the getchar
        if(c == ' '){ //if the character is a blank the if is going to happen
			while((c = getchar()) == ' '){  //getchar is going to read the next character, if it's a blank, we will skip it until there are no more blanks
				; // null statement
        }
            putchar(c); // to ensure to put the character if it is not a blank
		}

    }
}
