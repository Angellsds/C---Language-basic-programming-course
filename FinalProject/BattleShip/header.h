
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
int isdigit(int c);
