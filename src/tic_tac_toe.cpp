#include "tic_tac_toe.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    char pos;
    disp();
    while (turn < 9) {
        int temp = 0;
        while (temp == 0 && turn % 2 == 0) {
            cout << "\n Enter a position: ";
            cin >> pos;
            int idx = input(pos);
            if (idx != -1 && bord[idx] == 2) {
                gon(idx);
                turn++;
                move_type = 5;
                temp++;
            }
        }

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        disp();

        if (move_type == 5) {
            if (turn == 1) {
                gon(make2corner());
                move_type = 3;
                turn++;
            } else {
                int win_move = poswin(5);
                if (win_move != -1) {
                    gon(win_move);
                } else {
                    int block_move = poswin(3);
                    if (block_move != -1) {
                        gon(block_move);
                    } else if (turn == 3) {
                        gon(make3());
                    } else {
                        gon(make2());
                    }
                }
                turn++;
                move_type = 3;
            }
        }

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        disp();

        if (turn > 4) {
            if (check(3) == 1) {
                cout << "\nCongrats! You won!" << endl;
                return 0;
            } else if (check(5) == 1) {
                cout << "\nTry again later. Computer won!" << endl;
                return 0;
            }
        }
    }
    cout << "\nIt's a draw!" << endl;
    return 0;
}
