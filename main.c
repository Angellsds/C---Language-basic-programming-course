#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 10
#define COLUM 10
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

    if(*sort == 1){
            printf(x == 1 ? "\tP1 Result\n\n" : "\tP1 turn\n\n");
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j<COLUM; j++){
            printf("%c  ", myview[i][j]);
    }
        printf("\n");
        }
        printf("\n");
    }
    else{
            printf(x == 1 ? "\tP2 result\n\n" : "\tP2 turn\n\n");
    for(int i = 0; i<ROW; i++){
        for(int j = 0; j<COLUM; j++)
            printf("%c  ", enemyview[i][j]);
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

void win(int x){

    printf(x == 1 ? "\t\tP2 WIN\n": "\t\tP1 WIN\n");
    system("pause");
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
    generateships();
    while(1){
        int k = 0;
        showmap == 1 ? showboard(k):NULL;
        printf("Choose a coordinate using this syntax x,y: ");
        scanf("%d%c%d",&x,&checksyntx,&y);
        fflush(stdin);
            if((!isdigit(x) || !isdigit(y))&& x > 0 && y > 0 && x < ROW+1 && y < COLUM+1 && (checksyntx == ' ' || checksyntx == ',')){
                k = 1;
                system("cls");
                if(alreadyhited(y,x) == 1){continue;}
                int hit = attack(y,x);
                showboard(k);
                checkwin();
                if(*sort == 0){*sort = 1;} else{*sort = 0;}
                printf(hit == 1? "You choose coordinates (%d,%d) and you hit a ship\n": "You choose coordinates (%d,%d) and you did not hit a ship\n",x,y);
                showmap = 1;
                system("pause");
                system("cls");
            }
            else{
                printf("\nWrong input\n\n");
                showmap = 0;
            }
        }

}
