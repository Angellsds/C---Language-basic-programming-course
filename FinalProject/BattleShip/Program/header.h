#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>  //Library to use printf
#include <stdlib.h> //Use rand and srand
#include <ctype.h>  //isdigit
#include <time.h>   //to generate random numbers with time
#define ROW 9     //If you put more than 9, strange characters appear like rows and columns, but their value is still integer, 10, 11, 12, etc.
#define COLUM 9   //and it still works properly
#define MAXSHIPS 50 //Amount of ships

char myboard[ROW+1][COLUM+1];   //to set the real board
char myview[ROW+1][COLUM+1];    //to set the view of the board
char enemyboard[ROW+1][COLUM+1];    //set the real enemyboard
char enemyview[ROW+1][COLUM+1];     //set the enemy view board
int turn;   //variable with the turn
int *sort = &turn; //pointer to this variable

void setboard();    //function to set the board
void showboard();   //function to view the board
int random_turn(); //function to choose randomly the turn
void checkwin(); //function to see if someone wins
void generateships(); //function to generate the ships
int attack(int, int); //function to attack a coordinate
void win(int); //function that show the win screen
int alreadyhited(int, int); //function to check if the coordinate has already been chosen
void wait(); //function to stop the program until someone press a key


#endif // HEADER_H_INCLUDED
