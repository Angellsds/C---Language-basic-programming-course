//╔══╗──────╔╗──╔╗─╔╗─────────╔╗
//║╔╗║─────╔╝╚╗╔╝╚╗║║─────────║║
//║╚╝╚╗╔══╗╚╗╔╝╚╗╔╝║║─╔══╗╔══╗║╚═╗╔╗╔══╗
//║╔═╗║║╔╗║─║║──║║─║║─║║═╣║══╣║╔╗║╠╣║╔╗║
//║╚═╝║║╔╗║─║╚╗─║╚╗║╚╗║║═╣╠══║║║║║║║║╚╝║
//╚═══╝╚╝╚╝─╚═╝─╚═╝╚═╝╚══╝╚══╝╚╝╚╝╚╝║╔═╝
//──────────────────────────────────║║
//──────────────────────────────────╚╝


#include "header.h"


void setboard(){ //setting the board

    for(int i = 0; i<ROW+1; i++)
        for(int j = 0; j<COLUM+1; j++){ //loop to fill the real board with "o" and the viewboard with "+"
            for(int z = 1; z<COLUM+1; z++){ //this loop put numbers in the array to avoid printing numbers and take advantage of that to start at 1,1
            char c = '0'+z;  //setting a variable char that start from 1 to put it into the array
            myboard[0][z] = c;
            enemyboard[0][z] = c;
            myview[0][z] = c;
            enemyview[0][z] = c;
            myboard[z][0] = c;
            enemyboard[z][0] = c;
            myview[z][0] = c;
            enemyview[z][0] = c;
            }
            myboard[i+1][j+1] = 'o'; //filling the real board with "o"
            enemyboard[i+1][j+1] = 'o';
            myview[i+1][j+1] = '+'; //filling the viewboard with "+"
            enemyview[i+1][j+1] = '+';

        }
}

void showboard(int x){ //function to show the board

    int fix = 0; //a variable to fix a visual error
    if(*sort == 1){ //if that checks if is the P1 turn or P2 turn
        printf(x == 1 ? "\tP1 Result\n\n" : "\tP1 turn\n\n"); //printf with a condition to print if the board shown is the result of your guess or is your turn to guess
    for(int i = 0; i<ROW+1; i++){ //loop to show the array
        for(int j = 0; j<COLUM+1; j++){
            if(fix == 0){printf(" "); fix ++;} //if that fix that visual error
            printf("%c ", myview[i][j]); //print the character in that position and adding a space
         }
        printf("\n"); //printing an enter for each row
        }
        printf("\n");//printing an enter to have a better visual result
    }
    else{ //the same as before, only this is in case it is the enemy's turn
        printf(x == 1 ? "\tP2 result\n\n" : "\tP2 turn\n\n");
    for(int i = 0; i<ROW+1; i++){
        for(int j = 0; j<COLUM+1; j++){
            if(fix == 0){printf(" "); fix ++;}
            printf("%c ", enemyview[i][j]);
         }
        printf("\n");
        }
        printf("\n");
    }

}

int random_turn(){ //function to generate a random number between 0 and 1
    int number; //declaring a variable
    srand (time(NULL)); //initializing the random number generator
    number = rand()% 2; //getting the random number
    return number; //returning the value

}

void checkwin(){ //function to check if someone win

int mewin = 0; //set variables to better understand if someone won, what value to give
int enemywin = 1;

    int count = 0; //variable to storage the amount of "x"
    if(*sort == 1){ //if that checks the turn
    for(int i = 0; i<ROW; i++){ //loop that check the array looking for "x"
        for(int j = 0; j<COLUM; j++){
            if(myview[i][j] == 'x'){count ++; if(count == MAXSHIPS){win(mewin);}; //if to add 1 to count every time it finds an x and if count is equal to maxships, it means that P1 won
            }
        }
    }
}
    else{ //the same as before but with the P2 turn
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j<COLUM; j++){
            if(enemyview[i][j] == 'x'){count ++; if(count == MAXSHIPS){win(enemywin);};
                }
            }
        }
    }
}



void generateships(){ // function to generate the ships

        int s = 0; //variable to compare with the number of ships
        while(s < MAXSHIPS){ //while loop to make sure we don't put more variables than we set
           int x = 1 + rand()% ROW; //generating a random number between 1 and the ROW
           int y = 1 + rand()% COLUM; //generating a random number between 1 and the COLUM
           if(x > 0 && x < ROW+1 && y > 0 && y < COLUM+1 ){//if to make sure we don't put a ship where there was already one
           if(myboard[x][y] != 'b'){
                myboard[x][y] = 'b';
                s++;
                }
            }
        }
        s = 0; //resetting the counter

        while(s < MAXSHIPS){ //the same as before but with the enemy board
           int x = 1 + rand()% ROW;
           int y = 1 + rand()% COLUM;
           if(x > 0 && x < ROW+1 && y > 0 && y < COLUM+1 ){
           if(enemyboard[x][y] != 'b'){
                enemyboard[x][y] = 'b';
                s++;
                }
            }
        }

}

int attack(int x, int y){ //function to attack a coordinate

    if(*sort == 1){ //check the turn
        if(myboard[x][y] == 'b'){ //if that checks if there is a b in that position, if its true, set that position as an "x"
            myboard[x][y] = 'x';
            myview[x][y] = myboard[x][y];
            return 1;
        }
        else{ //if its not true, we put an "o" in that position
            myboard[x][y] = 'o';
            myview[x][y] = myboard[x][y];
            return 0;
        }
    }
    else{ //the same as before but with the enemy board in case it's his turn
        if(enemyboard[x][y] == 'b'){
            enemyboard[x][y] = 'x';
            enemyview[x][y] = enemyboard[x][y];
            return 1;
        }
        else{
            myboard[x][y] = 'o';
            enemyview[x][y] = enemyboard[x][y];
            return 0;
        }
    }
}

void wait () //function to wait until someone press a key
{
    puts("Press enter to continue...");
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdin,NULL,_IOFBF,BUFSIZ);
    getchar();
}

void win(int x){ //function to show the win screen

    printf(x == 1 ? "\t\tP2 WIN\n": "\t\tP1 WIN\n");
    wait();
    exit(1);
}

int alreadyhited(int i, int j){ //function to check if the coordinate has already been chosen

    if(*sort == 1){ //check the turn
        if(myview[i][j] == 'x' || myview[i][j] == 'o'){ //if that position is an "x" or "o"
            printf("\tLocation already chosen\n"); //print this thing
            return 1;
            }
        }
    else{ //the same as before but with the enemy board in case it's his turn
        if(enemyview[i][j] == 'x' || enemyview[i][j] == 'o'){
            printf("\tLocation already chosen\n");
            return 1;
            }
        }
}

int main(void){ //main function

    int x =0,y =0, showmap =1; //declaring some variables
    char checksyntx; //variable to check the syntax
    if(MAXSHIPS>ROW*COLUM){printf("Number of ships exceeds the board\n");exit(1);} //if that check that the number of ships does not exceed the size of the board
    setboard(); //calling the setboard function
    *sort = random_turn(); //choosing the turn randomly
    printf("    Welcome to BattleShip\n\n"); //printing instructions
    printf("Instructions\n");
    printf("1. You have to defeat your opponent by destroying all his war ships before he destroys yours.\n");
    printf("2. You have a fleet of N battle ships\n");
    printf("3. The turn is chosen to see who will play first and it is shown above whose turn it is\n");
    printf("4. After the ships are placed, you can attack the enemy area. To attack a specific area, enter its x y coordinate(separated by a space or ,)\n");
    printf("5. If your attack hits the enemy ship, the new board will be shown and it will be denoted by an 'X' and your turn continues.\n");
    printf("6. If your attack misses, the new board will be shown and it will be denoted by a 'o' and your turn ends.\n");
    printf("7. And now the opponent's turn will follow\n");
    printf("The first to shoot down the entire enemy fleet wins\n\n");
    generateships(); //generating ships
    wait(); //calling wait function
    system("cls"); //clearing the console
    //system("clear");
    while(1){ //while to repeat infinitely
        int k = 0; //variable that checks if a coordinate has already been chosen
        showboard(k); //call the showboard function
        puts("Choose a coordinate using this syntax x,y: "); //using put because printf before it generates errors
        scanf("%d%c%d",&x,&checksyntx,&y); //asking for the coordinates
        fflush(stdin); //cleaning the input
            if((!isdigit(x) || !isdigit(y)) && x > 0 && y > 0 && x <= ROW && y <= COLUM && (checksyntx == ' ' || checksyntx == ',')){ //if that checks if the coordinate is a number and is a valid coordinate
                k = 1; //setting k as 1
                if(alreadyhited(y,x) == 1){/*system("clear");*/system("cls");printf("   Location already chosen\n");continue;} //if that checks if the the coordinate was already chosen and repeat the loop
                int hit = attack(y,x); //hit that position
                if(hit == 1){/*system("clear");*/system("cls");showboard(k);printf("You choose coordinates (%d,%d) and you hit a ship\n",x,y);wait();/*system("clear");*/system("cls");continue;}//if to reset the turn in case we hit a ship
                system("cls"); //cleaning the terminal
                //system("clear");
                showboard(k); //showing the board
                checkwin(); //checking if someone win
                if(*sort == 0){*sort = 1;} else{*sort = 0;} //exchanging between turns
                printf("You choose coordinates (%d,%d) and you did not hit a ship\n",x,y); //printf showing that we did not hit a ship
                wait(); //calling wait function
                system("cls"); //cleaning the terminal
                //system("clear");
            }
            else{ //if we do not write valid coordinates
                system("cls"); //cleaning the terminal
                //system("clear");
                printf("   Invalid coordinate\n"); //printing invalid coordinates
            }
        }

}

//some information about random http://programacionnerd.blogspot.com/2012/05/c-generando-numeros-aleatorios-random.html
//int isdigit http://www.w3big.com/es/cprogramming/c-function-isdigit.html
