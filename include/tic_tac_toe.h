#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>

extern int mgsqr[];
extern int mgsqr2[];
extern int bord[];
extern int move_type;
extern int turn;

int check(int move);
int make2();
int make2corner();
int make3();
void gon(int n);
int input(char p);
void disp();
int poswin(int p);
void reset_game();

#endif // TIC_TAC_TOE_H
