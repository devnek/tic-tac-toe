#include "tic_tac_toe.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int mgsqr[] = {8, 3, 4, 1, 5, 9, 6, 7, 2};
int mgsqr2[] = {-1, 3, 8, 1, 2, 4, 6, 7, 0, 5};
int bord[] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
int move_type = 3;
int turn = 0;

void reset_game() {
    for (int i = 0; i < 9; i++) bord[i] = 2;
    move_type = 3;
    turn = 0;
}

int check(int move) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if (i != j && j != k && k != i) {
                    if (bord[i] == move && bord[j] == move && bord[k] == move) {
                        if (mgsqr[i] + mgsqr[j] + mgsqr[k] == 15) return 1;
                    }
                }
            }
        }
    }
    return -1;
}

int make2() {
    if (bord[4] == 2) return 4;
    int attempts = 0;
    while (attempts < 100) {
        if (bord[1] == 2 || bord[3] == 2 || bord[5] == 2 || bord[7] == 2) {
            int a = rand() % 4;
            switch (a) {
                case 0: if (bord[1] == 2) return 1; break;
                case 1: if (bord[3] == 2) return 3; break;
                case 2: if (bord[5] == 2) return 5; break;
                case 3: if (bord[7] == 2) return 7; break;
            }
        } else break;
        attempts++;
    }
    return -1;
}

int make2corner() {
    if (bord[4] == 2) return 4;
    int attempts = 0;
    while (attempts < 100) {
        if (bord[0] == 2 || bord[2] == 2 || bord[6] == 2 || bord[8] == 2) {
            int a = rand() % 4;
            switch (a) {
                case 0: if (bord[0] == 2) return 0; break;
                case 1: if (bord[2] == 2) return 2; break;
                case 2: if (bord[6] == 2) return 6; break;
                case 3: if (bord[8] == 2) return 8; break;
            }
        } else break;
        attempts++;
    }
    return -1;
}

int make3() {
    int i;
    for (i = 0; i < 9; i++) if (bord[i] == 5) break;
    if (i == 9) return -1;
    int a = rand() % 2;
    if (i == 1 || i == 7) {
        if (a == 1 && (i-1 >= 0) && bord[i-1] == 2) return (i - 1);
        else if ((i+1 < 9) && bord[i+1] == 2) return (i + 1);
    } else if (i == 3 || i == 5) {
        if (a == 1 && (i-3 >= 0) && bord[i-3] == 2) return (i - 3);
        else if ((i+3 < 9) && bord[i+3] == 2) return (i + 3);
    }
    return -1;
}

void gon(int n) {
    if (n >= 0 && n < 9) {
        if (turn % 2 == 0) bord[n] = 3;
        else bord[n] = 5;
    }
}

int input(char p) {
    switch (p) {
        case 'q': return 0;
        case 'w': return 1;
        case 'e': return 2;
        case 'a': return 3;
        case 's': return 4;
        case 'd': return 5;
        case 'z': return 6;
        case 'x': return 7;
        case 'c': return 8;
        default: return -1;
    }
}

void disp() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) cout << endl;
        if (bord[i] == 2) cout << " _";
        else if (bord[i] == 3) cout << " X";
        else cout << " O";
    }
    cout << endl;
}

int poswin(int p) {
    for (int i = 0; i < 8; i++) {
        if (bord[i] == p) {
            for (int j = i + 1; j < 9; j++) {
                if (bord[j] == p) {
                    int sum = mgsqr[i] + mgsqr[j];
                    if (sum > 5 && sum < 15) {
                        int remaining = 15 - sum;
                        // Find index in mgsqr where value is 'remaining'
                        for(int k=0; k<9; k++) {
                            if(mgsqr[k] == remaining && bord[k] == 2) return k;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
