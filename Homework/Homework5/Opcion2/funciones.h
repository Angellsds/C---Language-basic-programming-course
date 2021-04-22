#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define FLUSH fflush(stdin)
#include "funciones.c"

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
void error(void);

#endif // FUNCIONES_H_INCLUDED
