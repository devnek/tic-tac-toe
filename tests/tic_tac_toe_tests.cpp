#include <gtest/gtest.h>
#include "tic_tac_toe.h"

class TicTacToeTest : public ::testing::Test {
protected:
    void SetUp() override {
        reset_game();
    }
};

TEST_F(TicTacToeTest, InputMapping) {
    EXPECT_EQ(input('q'), 0);
    EXPECT_EQ(input('w'), 1);
    EXPECT_EQ(input('e'), 2);
    EXPECT_EQ(input('a'), 3);
    EXPECT_EQ(input('s'), 4);
    EXPECT_EQ(input('d'), 5);
    EXPECT_EQ(input('z'), 6);
    EXPECT_EQ(input('x'), 7);
    EXPECT_EQ(input('c'), 8);
    EXPECT_EQ(input('k'), -1);
}

TEST_F(TicTacToeTest, GonUpdatesBoard) {
    turn = 0; // X's turn
    gon(0);
    EXPECT_EQ(bord[0], 3);
    
    turn = 1; // O's turn
    gon(1);
    EXPECT_EQ(bord[1], 5);
}

TEST_F(TicTacToeTest, CheckWin) {
    // X wins on first row
    bord[0] = 3; bord[1] = 3; bord[2] = 3;
    EXPECT_EQ(check(3), 1);
    
    reset_game();
    // O wins on diagonal
    bord[0] = 5; bord[4] = 5; bord[8] = 5;
    EXPECT_EQ(check(5), 1);
}

TEST_F(TicTacToeTest, PosWinDetection) {
    // X about to win on first row
    bord[0] = 3; bord[1] = 3; bord[2] = 2;
    EXPECT_EQ(poswin(3), 2);
    
    reset_game();
    // O about to win on column
    bord[0] = 5; bord[3] = 5; bord[6] = 2;
    EXPECT_EQ(poswin(5), 6);
}

TEST_F(TicTacToeTest, Make2PreferCenter) {
    reset_game();
    EXPECT_EQ(make2(), 4);
}

TEST_F(TicTacToeTest, Make2CornerPreferCenter) {
    reset_game();
    EXPECT_EQ(make2corner(), 4);
}

TEST_F(TicTacToeTest, Make3AI) {
    reset_game();
    bord[1] = 5; // O at index 1
    int move = make3();
    EXPECT_TRUE(move == 0 || move == 2);
}
