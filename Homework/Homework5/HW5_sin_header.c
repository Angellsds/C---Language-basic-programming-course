//Version sin utilizar header

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

#define FLUSH fflush(stdin)

void game_mode(void);
void default_minefield(void);
void minefield_generator(void);
void print_minefield(void);
void answer(void);
void mine(void);
void print_final_minefield(void);
void win(void);
void play_again(void);
void game_over(void);
void custom(void);
void error(void)

int x, y;
int M, N; //coulm, row
float mode, y_n;
int total_mines = 0;
int mines = 0;
int minefield[25][25];                                      //2-D array que contiene minas, numeros y espacios
int blank_minefield[25][25];                                //Contiene el campo lleno de "#"
int final_minefield[25][25];

int main()
{
    printf("\t\tWelcome to Minesweeper\n");
    game_mode();
    return 0;
}

void game_mode(void)                                     //Funcion para elegir modo de juego
{
    mode = 0;
    while( (mode != 1) && (mode != 2) )
    {
        printf("\t\tChoose 1 for a 10 x 10 or 2 for a custom minefield: ");
        scanf("%f", &mode);
        FLUSH;
        if( (mode != 1) && (mode != 2) )
        {
            system("cls");
            printf("\t\tPlease enter either 1 or 2\n");
        }
    }

    if( mode == 1 )                                         //If y else if statements que llevan al respectivo modo de juego
        default_minefield();
    else if( mode == 2 )
        custom();
}

void default_minefield(void)                                       //Da el campo default de 10 x 10
{
    M = 10;
    N = 10;
    float y_n = 0;
    total_mines = 0;
    system("cls");
    printf("\t\tDo you want to generate random number of mines?\n");
    printf("\t\tType 1 for yes 2 for no: ");
        scanf("%f", &y_n);
        if(y_n == 1){
        srand(time(NULL));
        total_mines = rand () % (25-11) + 10;                   //Genera numero random de minas entre 10 y 25
        minefield_generator();
        answer();
        }
    if(y_n == 2){
        printf("\t\tNumber of mines you want to assign to the board: ");   //Asignar cantidad de minas
        scanf("%d", &total_mines);
        FLUSH;
            if( total_mines > (M * N))
                error();
        minefield_generator();
        answer();
}
    default_minefield();
}
void error(void)                                                        //En caso de agregar mas minas que la cantidad de cuadriculas
{
   system("cls");
   printf("\n\t\tNumber of mines assigned to the board does not fit\n\n\t\t");
   system("pause");
   system("cls");
   game_mode();
}

void custom(void)                                                   //Para dar los valores al tablero custom
{
    M = 0;
    N = 0;
    total_mines = 0;
    system("cls");
    printf("\t\tPlease enter the size of the dimensions you want\n");
    printf("\t\tFirst value: ");
        scanf("%d", &M);
    printf("\t\tSecond value: ");
        scanf("%d", &N);
    printf("\t\tNumber of mines you want to assign to the board: ");
        scanf("%d", &total_mines);
        if( total_mines > (M * N))
        error();
    minefield_generator();
    answer();
}

void minefield_generator(void)                            //Funcion para generar el campo
{
    int i = 0, j = 0;
    srand(time(NULL));                                  //Instrucción que inicializa el generador de números aleatorios

    for(j = 0; j < N; j++){                                          //Loop para llenar el campo de # y copiarselo a los otros arrgelos
        for(i = 0; i < M; i++){
            minefield[i][j] = '#';
            blank_minefield[i][j] = minefield[i][j];
            final_minefield[i][j] = minefield[i][j];
        }
        i = 0;
    }
    mines = 0;
    while(mines < total_mines){                            //Generar aleatoriamente minas en el campo
        i = rand()%(M);                                    //Elige un numero aleatorio entre 0 y M-1
        j = rand()%(N);                                    //Elige un numero aleatorio entre 0 y M-1
        if( minefield[i][j] != EOF){                         //If para verificar si no hay una mina colocada en el mismo lugar
            minefield[i][j] = EOF;
            final_minefield[i][j] = minefield[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    while( j < N ){                                          //While loop que genera numeros a las minas adyacentes
        while( i < M){
                if( minefield[i][j] != EOF){
                    minefield[i][j] = 0;
                }
                if((minefield[i-1][j-1] == EOF) && (minefield[i][j] != EOF)){
                    minefield[i][j]++;
                }
                if((minefield[i-1][j] == EOF) && (minefield[i][j] != EOF)){
                    minefield[i][j]++;
                }
                if((minefield[i][j-1] == EOF) && (minefield[i][j] != EOF)){
                    minefield[i][j]++;
                }
                if((minefield[i-1][j+1] == EOF) && (minefield[i][j] != EOF)){
                    minefield[i][j]++;
                }
                if((minefield[i+1][j-1] == EOF) && (minefield[i][j] != EOF)){
                    minefield[i][j]++;
                }
                if((minefield[i+1][j] == EOF) && (minefield[i][j] != EOF)){
                    minefield[i][j]++;
                }
                if((minefield[i][j+1] == EOF) && (minefield[i][j] != EOF)){
                    minefield[i][j]++;
                }
                if((minefield[i+1][j+1] == EOF) && (minefield[i][j] != EOF)){
                    minefield[i][j]++;
                }
                i++;
            }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}

void print_minefield(void){                                  // Imprime el campo

    int i = 0, j = 0, z = 0;
    while( z < M ){                                          // Loop para imprimir los numeros en el eje de las x
        if( z == 0 ){
            printf("\t");
        }
        printf("%d\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N ){                                          // Loop que imprime cada caracter en el campo
        printf("%d\t", j);
        while( i < M){
            if( blank_minefield[i][j] == '#'){
                printf("%c\t", blank_minefield[i][j]);

            }
            else if( minefield[i][j] == 0 ){                 // Cambia cualquier valor de 0 con ' '
                blank_minefield[i][j] = ' ';
                printf("%c\t", blank_minefield[i][j]);
            }
            else
                printf("%d\t", blank_minefield[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}


void answer(void)
{
    int q = 0, i=0, j=0, match=0;
    print_minefield();
    while( j < N ){                                          // While loop para verificar si el jugador ya limpio el campo
        while( i < M ){
            if(minefield[i][j] == blank_minefield[i][j])
                match++;
            i++;
        }
        i = 0;
        j++;
    }
    if( match == (( M * N ) - total_mines)){                 // Si ya limpio el campo, la funcion win() se realizara
        win();
    }
    printf("\nEnter the x value, then a space, then the y value:");
    scanf("%d %d", &x, &y);                                 // Leyendo las coordenadas
    FLUSH;
    system("cls");
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) ){
        printf("\nPlease enter a value inside the grid\n");
        answer();
    }
    if( minefield[x][y] == EOF ){                            // Empieza la funcion mine si el jugador selecciona una mina
        mine();
    }
    if( blank_minefield[x][y] != '#' )
    {
        printf("\nPlease enter a value that has not already been entered\n");
        answer();
    }

    else                                                // Verifica si los espacios adyacentes son blancos, y despues cambia los valores en el array blank_minefield. Como cambiaron, ahora se imprimirán en la función print minefield
    {
        blank_minefield[x][y] = minefield[x][y];
        if( minefield[x][y] == 0 ){
            if( minefield[x-1][y-1] == 0 ){
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x-1][y] == 0 ){
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x][y-1] == 0 ){
                blank_minefield[x][y-1] = minefield[x][y-1];
            }
            if( minefield[x-1][y+1] == 0 ){
                blank_minefield[x-1][y+1] = minefield[x-1][y+1];
            }
            if( minefield[x+1][y-1] == 0 ){
                blank_minefield[x+1][y-1] = minefield[x+1][y-1];
            }
            if( minefield[x+1][y] == 0 ){
                blank_minefield[x+1][y] = minefield[x+1][y];
            }
            if( minefield[x][y+1] == 0 ){
                blank_minefield[x][y+1] = minefield[x][y+1];
            }
            if( minefield[x+1][y+1] == 0 ){
                blank_minefield[x+1][y+1] = minefield[x+1][y+1];
            }
        }
        answer();
    }
}

void mine(void){                                       // Muestra el campo de minas y llama la funcion de jugar de nuevo
    print_final_minefield();
    printf("\n\t\tYou hit a mine at (%d , %d)\n", x, y);
    play_again();
}

void print_final_minefield(void)                      // Imprime el campo de minas y muestra donde estaban las minas
{
    int i = 0, j = 0, z = 0;
    while( z < M ){
        if( z == 0 ){
            printf("\t");
        }
        printf("%d\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N ){
        printf("%d\t", j);
        while( i < M){
            printf(final_minefield[i][j] == '#' ? " %c\t" : "%d\t" , final_minefield[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void win(void){                                       // Cuando ganas, llama la funcion de jugar de nuevo
    printf("\n\n\n\t\t\tYOU WIN!!!!!\n\n\n");
    play_again();
}

void play_again(void)                                 // Da la opcion de jugar de nuevo
{
    char option[2];
    printf("\n\t\tWould you like to play again(Y/N)?:");
    scanf("%c", &option[0]);
    FLUSH;
    if((option[0] == 'Y') || (option[0] == 'y')){        // Reinicia el programa
        system("cls");
        game_mode();
    }
    else if( (option[0] == 'N') || (option[0] == 'n')){
        game_over();
    }
    else{
        printf("\t\tPlease enter either Y or N\n");
        play_again();
    }
}

void game_over(void)                                  // Finaliza el programa
{
    printf("\n\n\t\tGame Over");
    exit(1);
}


