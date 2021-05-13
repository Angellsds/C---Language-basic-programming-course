//Remove // from system("cls") if you are using the command prompt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 10-     //If you put more than 10, strange characters appear like rows and columns, but their value is still integer, 10, 11, 12, etc.
#define COLUM 10   //and it still works properly
#define MAXSHIPS 15

char myboard[ROW+1][COLUM+1];
char myview[ROW+1][COLUM+1];
char enemyboard[ROW+1][COLUM+1];
char enemyview[ROW+1][COLUM+1];
int turn;
int check;
int *sort = &turn;
int *checkk = &check;

void setboard();
void showboard();
int random_turn();
void checkwin();
void generateships();
int attack(int, int);
void win(int);
int alreadyhited(int, int);
int isdigit(int c);
void wait();


void setboard(){

    for(int i = 0; i<ROW; i++)
        for(int j = 0; j<COLUM; j++){
            for(int z = 1; z<COLUM+1; z++){
            char c = '0'+z;
            myboard[0][z] = c;
            enemyboard[0][z] = c;
            myview[0][z] = c;
            enemyview[0][z] = c;
            myboard[z][0] = c;
            enemyboard[z][0] = c;
            myview[z][0] = c;
            enemyview[z][0] = c;
            }
            myboard[i+1][j+1] = 'o';
            enemyboard[i+1][j+1] = 'o';
            myview[i+1][j+1] = '+';
            enemyview[i+1][j+1] = '+';

        }
}

void showboard(int x){
    
    int fix = 0;
    if(*sort == 1){
        printf(x == 1 ? "\tP1 Result\n\n" : "\tP1 turn\n\n");
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j<COLUM; j++){
            if(fix == 0){printf(" "); fix ++;}
            printf("%c ", myview[i][j]);
         }
        printf("\n");
        }
        printf("\n");
    }
    else{
        printf(x == 1 ? "\tP2 result\n\n" : "\tP2 turn\n\n");
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j<COLUM; j++){
            if(fix == 0){printf(" "); fix ++;}
            printf("%c ", enemyview[i][j]);
         }
        printf("\n");
        }
        printf("\n");
    }

}

int random_turn(){
    int number;
    srand (time(NULL));
    number = rand()% 2;
    return number;

}

void checkwin(){

int mewin = 0;
int enemywin = 1;

    int count = 0;
    if(*sort == 1){
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j<COLUM; j++){
            if(myview[i][j] == 'x'){count ++; if(count == MAXSHIPS){win(mewin);};
            }
        }
    }
}
    else{
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j<COLUM; j++){
            if(enemyview[i][j] == 'x'){count ++; if(count == MAXSHIPS){win(enemywin);};
                }
            }
        }
    }
}



void generateships(){

    if(*checkk == 0 ){*sort = random_turn(); *checkk = 1;}

        int s = 0;
        while(s <= MAXSHIPS){
           int x = 1 + rand()% ROW;
           int y = 1 + rand()% COLUM;
           if(x > 0 && x < ROW && y > 0 && y < COLUM ){
           if(myboard[x][y] != 'b'){
                myboard[x][y] = 'b';
                s++;
                }
            }
        }
        s = 0;

        while(s <= MAXSHIPS){
           int x = 1 + rand()% ROW;
           int y = 1 + rand()% COLUM;
           if(x > 0 && x < ROW && y > 0 && y < COLUM ){
           if(enemyboard[x][y] != 'b'){
                enemyboard[x][y] = 'b';
                s++;
                }
            }
        }

}

int attack(int x, int y){

    if(*sort == 1){
        if(myboard[x][y] == 'b'){
            myboard[x][y] = 'x';
            myview[x][y] = myboard[x][y];
            return 1;
        }
        else{
            myboard[x][y] = 'o';
            myview[x][y] = myboard[x][y];
            return 0;
        }
    }
    else{
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

void wait ()
{
    puts("Press enter to continue...");
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdin,NULL,_IOFBF,BUFSIZ);
    getchar();
}

void win(int x){

    printf(x == 1 ? "\t\tP2 WIN\n": "\t\tP1 WIN\n");
    wait();
    exit(1);
}

int alreadyhited(int i, int j){

    if(*sort == 1){
        if(myview[i][j] == 'x' || myview[i][j] == 'o'){
            printf("\tLocation already choosed\n");
            return 1;
            }
        }
    else{
        if(enemyview[i][j] == 'x' || enemyview[i][j] == 'o'){
            printf("\tLocation already choosed\n");
            return 1;
            }
        }
}

int main(void){

    int x =0,y =0, showmap =1;
    char checksyntx;
    setboard();
    printf("    Welcome to BattleShip\n");
    printf("Instructions\n");
    printf("1. You have to defeat your opponent by destroying all his war ships before he destroys yours.\n");
    printf("2. Its x y coordinates (both separated by a space or ,) where x is the row number and y is the column number\n");
    printf("3. You have a fleet of N battle ships\n");
    printf("4. After the ships are placed, you can attack the enemy area. To attack a specific area, enter its x y coordinate (separated by a space or ,)\n");
    printf("5. If your attack hits the enemy ship, it will be denoted by an \'x\' and your turn ends.\n");
    printf("6. If your attack misses, it will be denoted by a \'o\' and your turn ends\n");
    generateships();
    wait();
    while(1){
        int k = 0;
        showmap == 1 ? showboard(k):NULL;
        puts("Choose a coordinate using this syntax x,y: ");
        scanf("%d%c%d",&x,&checksyntx,&y);
        fflush(stdin);
            if((!isdigit(x) || !isdigit(y)) && x > 0 && y > 0 && x < ROW+1 && y < COLUM+1 && (checksyntx == ' ' || checksyntx == ',')){
                k = 1;
                //system("cls");
                if(alreadyhited(y,x) == 1){continue;}
                int hit = attack(y,x);
                showboard(k);
                checkwin();
                if(*sort == 0){*sort = 1;} else{*sort = 0;}
                printf(hit == 1? "You choose coordinates (%d,%d) and you hit a ship\n": "You choose coordinates (%d,%d) and you did not hit a ship\n",x,y);
                showmap = 1;
                wait();
                //system("cls");
            }
            else{
                printf("\nWrong input\n\n");
                showmap = 0;
            }
        }

}

//some information about random http://programacionnerd.blogspot.com/2012/05/c-generando-numeros-aleatorios-random.html
//int isdigit http://www.w3big.com/es/cprogramming/c-function-isdigit.html
